#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct STree {
  #define ls (k<<1)+1
  #define rs (k<<1)+2
  #define lp ls, s, m
  #define rp rs, m, e
  struct Node { int sum, cnt; };
  int n;
  vector<Node> st;
  STree(int n) : n(n), st((n<<2)+5, {0, 0}) {}
  Node comb(Node a, Node b) {
    return {a.sum + b.sum, a.cnt + b.cnt};
  }
  void upd(int k, int s, int e, int i, int v) {
    if (s + 1 == e) {
      st[k].sum += v;
      if (v > 0)  ++st[k].cnt;
      else        --st[k].cnt;
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) upd(lp, i, v);
    else       upd(rp, i, v);
    st[k] = comb(st[ls], st[rs]);
  }
  void upd(int i, int v) {
    return upd(0, 0, n, i, v);
  }
  Node query(int k, int s, int e, int low) {
    if (s >= low) return st[k];
    int m = (s + e) >> 1;
    Node ans = query(rp, low);
    if (m > low) ans = comb(ans, query(lp, low));
    return ans;
  }
  Node query(int low) { return query(0, 0, n, low); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k, q;
  cin >> m >> n >> k >> q;

  vector<vi> a(n, vi(m, 1));
  FOR (_, 0, k) {
    int x0, y0, x1, y1;
    cin >> x0 >> x1 >> y0 >> y1;
    FOR (i, y0, y1) FOR (j, x0, x1) a[i][j] = 0;
  }

  vector<vector<pi>> Q(m + 1);
  FOR (i, 0, q) {
    int a, b;
    cin >> b >> a;
    Q[b].pb({a, i});
  }

  STree st(m + 1);
  vector<pi> out;
  vector<set<int>> black(m);
  FOR (j, 0, m) {
    black[j].insert(-1);
    black[j].insert(n);
    FOR (i, 0, n) if (!a[i][j]) {
      black[j].insert(i);
      if (j && a[i][j - 1]) out.pb({i, j - 1});
    }
    int l = 0;
    FOR (i, 0, n) {
      if (a[i][j]) {
        ++l;
        continue;
      }
      if (!l) continue;
      st.upd(l, l);
      l = 0;
    }
    if (l) st.upd(l, l);
  }
  FOR (i, 0, n) if (a[i][m - 1]) out.pb({i, m - 1});

  vi ans(q);
  FOR (b, 1, m + 1) {
    for (auto &[a, i] : Q[b]) {
      auto [sum, cnt] = st.query(a);
      ans[i] = sum + cnt * (1 - a);
    }
    vector<pi> next_out;
    for (auto &[i, j] : out) {
      auto it = black[j].lower_bound(i);
      int r = *it - 1, l = *(--it) + 1, len = r - l + 1;
      st.upd(len, -len);
      if (l != i) st.upd(i - l, i - l);
      if (r != i) st.upd(r - i, r - i);
      black[j].insert(i);
      if (j && a[i][j - 1]) next_out.pb({i, j - 1});
    }
    out.swap(next_out);
  }

  for (auto &x : ans) cout << x << ENDL;

  return 0;
}