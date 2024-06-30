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

#define NEUT 1e9
#define oper(a, b) (min(a, b))
template <class T>
struct SegTree {
  int n;
  vector<T> A, id;
  vector<pi> st;

  inline int lc(int p) { return (p << 1) + 1; }
  inline int rc(int p) { return (p << 1) + 2; }

  void init(int tn, int* th, int* tid) {
    n = tn;
    A.resize(n);
    id.resize(n);
    st.resize(n * 4);
    copy(th, th + n, A.begin());
    copy(tid, tid + n, id.begin());
    build(0, 0, n - 1);
  }

  void build(int p, int L, int R) {
    if (L == R) {
      st[p] = {A[L], id[L]};
      return;
    }
    int m = (L + R) >> 1;
    build(lc(p), L, m);
    build(rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }

  pair<T, T> query(int l, int r, int p, int L, int R) {
    if (l <= L && r >= R) return st[p];
    if (l > R || r < L) return {NEUT, -1};
    int m = (L + R) >> 1;
    return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
  }
  pair<T, T> query(int l, int r) { return query(l, r, 0, 0, n - 1); }

  void update(int i, T val, int p, int L, int R) {
    if (L > i || R < i) return;
    if (L == R) {
      st[p].first = val;
      return;
    }
    int m = (L + R) >> 1;
    update(i, val, lc(p), L, m);
    update(i, val, rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }
  void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

#define N 100010

int n, k;
int timer = -1;
int p[N];
int h[N];
int st[N], en[N], th[N], tid[N];
vi g[N];

void dfs(int u) {
  st[u] = ++timer;
  th[timer] = h[u];
  tid[timer] = u;
  for (auto &v : g[u]) {
    if (v == p[u]) {
      continue;
    }
    h[v] = h[u] + 1;
    p[v] = u;
    dfs(v);
  }
  en[u] = timer;
}

priority_queue<int> pq;
SegTree<int> seg;

int max_k_processed[N]; 
void process(int u, int k) {
  if (k <= max_k_processed[u] || u == -1) {
    return;
  }
  max_k_processed[u] = k;
  while (1) {
    auto [he, v] = seg.query(st[u], en[u]);
    if (he - h[u] > k) {
      break;
    }
    pq.push(-v);
    seg.update(st[v], NEUT);
  }
  process(p[u], k - 1);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> k;
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v), g[v].pb(u);
  }

  memset(max_k_processed, -1, sizeof max_k_processed);

  p[0] = -1;
  dfs(0);

  seg.init(timer + 1, th, tid);
  seg.update(0, NEUT);
  pq.push(0);
  while (!pq.empty()) {
    int u = -pq.top();
    pq.pop();
    cout << u + 1 << ' ';
    process(u, k);
  }
  cout << ENDL;

  return 0;
}