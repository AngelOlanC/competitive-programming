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

constexpr ll INF = 1e18;

#define NEUT -INF
#define oper(a, b) max(a, b)
template <class T>
struct SegTree {
  int n;
  vector<T> A, st;

  inline int lc(int p) { return (p << 1) + 1; }
  inline int rc(int p) { return (p << 1) + 2; }

  void init(vector<T> v) {
    A = v;
    n = SZ(A);
    st.resize(n * 4);
    build(0, 0, n - 1);
  }

  void build(int p, int L, int R) {
    if (L == R) {
      st[p] = A[L];
      return;
    }
    int m = (L + R) >> 1;
    build(lc(p), L, m);
    build(rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }

  T query(int l, int r, int p, int L, int R) {
    if (l <= L && r >= R) return st[p];
    if (l > R || r < L) return NEUT;
    int m = (L + R) >> 1;
    return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
  }
  T query(int l, int r) { return query(l, r, 0, 0, n - 1); }

  void update(int i, T val, int p, int L, int R) {
    if (L > i || R < i) return;
    if (L == R) {
      st[p] = val;
      return;
    }
    int m = (L + R) >> 1;
    update(i, val, lc(p), L, m);
    update(i, val, rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }
  void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, c, m;
  cin >> n >> c >> m;
  
  SegTree<ll> sl, sr;
  sl.init(vector<ll>(n, -INF));
  sr.init(vector<ll>(n, -INF));
  sl.update(0, 0);

  ll ans = 0;
  FOR (i, 1, m + 1) {
    // cout << i << ENDL;
    ll t, p;
    cin >> t >> p;
    --t;
    ll curr = p - c * t + sl.query(t, t);
    if (t) {
      curr = max(curr, p - c * t + sl.query(0, t - 1));
    }
    if (t != n - 1) {
      // cout << "looking right of " << t << " " << sr.query(t + 1, n - 1) << ENDL;
      curr = max(curr, p + c * t + sr.query(t + 1, n - 1));
    }
    // cout << "current " << curr << ENDL;

    ans = max(ans, curr);
    // cout << "update left " << curr + 1ll * c * t << ENDL;
    // cout << "update right " << curr - 1ll * c * t << ENDL;
    sl.update(t, curr + 1ll * c * t);
    sr.update(t, curr - 1ll * c * t);
    // assert(sl.query(t, t) == curr + 1ll * c * t);
    // assert(sr.query(t, t) == curr - 1ll * c * t);
  }
  cout << ans << ENDL;  
  
  return 0;
}