#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct RollbackDSU {
  vector<int> e;
  vector<pair<int, int>> st;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  int time() { return st.size(); }
  void rollback(int t) {
    for (int i = time(); i --> t;)
      e[st[i].first] = st[i].second;
    st.resize(t);
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

struct Edge { int a, b; ll w; };
struct Node { /// lazy skew heap node
	Edge key;
	Node *l, *r;
	ll delta;
	void prop() {
		key.w += delta;
		if (l) l->delta += delta;
		if (r) r->delta += delta;
		delta = 0;
	}
	Edge top() { prop(); return key; }
};
Node *merge(Node *a, Node *b) {
	if (!a || !b) return a ?: b;
	a->prop(), b->prop();
	if (a->key.w > b->key.w) swap(a, b);
	swap(a->l, (a->r = merge(b, a->r)));
	return a;
}
void pop(Node*& a) { a->prop(); a = merge(a->l, a->r); }

pair<ll, vi> dmst(int n, int r, vector<Edge>& g) {
	RollbackDSU uf; uf.init(n);
	vector<Node*> heap(n);
	for (Edge e : g) heap[e.b] = merge(heap[e.b], new Node{e});
	ll res = 0;
	vi seen(n, -1), path(n), par(n);
	seen[r] = r;
	vector<Edge> Q(n), in(n, {-1,-1}), comp;
	deque<tuple<int, int, vector<Edge>>> cycs;
	FOR(s,0,n) {
		int u = s, qi = 0, w;
		while (seen[u] < 0) {
			if (!heap[u]) return {-1,{}};
			Edge e = heap[u]->top();
			heap[u]->delta -= e.w, pop(heap[u]);
			Q[qi] = e, path[qi++] = u, seen[u] = s;
			res += e.w, u = uf.get(e.a);
			if (seen[u] == s) { /// found cycle, contract
				Node* cyc = 0;
				int end = qi, time = uf.time();
				do cyc = merge(cyc, heap[w = path[--qi]]);
				while (uf.join(u, w));
				u = uf.get(u), heap[u] = cyc, seen[u] = -1;
				cycs.push_front({u, time, {&Q[qi], &Q[end]}});
			}
		}
		FOR(i,0,qi) in[uf.get(Q[i].b)] = Q[i];
	}

	for (auto [u,t,comp] : cycs) { // restore sol (optional)
		uf.rollback(t);
		Edge inEdge = in[u];
		for (auto& e : comp) in[uf.get(e.b)] = e;
		in[uf.get(inEdge.b)] = inEdge;
	}
	FOR(i,0,n) par[i] = in[i].a;
	return {res, par};
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Edge> g;
  FOR (i, 1, n + 1) {
    int x, s;
    cin >> x >> s;
    g.pb({x, i, s});
    FOR (j, 0, n + 1) {
      cin >> s;
      g.pb({j, i, s});
    }
  }
  cout << dmst(n + 1, 0, g).first << ENDL;

  return 0;
}