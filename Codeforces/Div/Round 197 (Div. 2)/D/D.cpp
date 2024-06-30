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

#define NEUT 0
#define oper(a, b) (polarity == h % 2 ? (a ^ b) : (a | b))
template <class T>
struct SegTree {
  int n, polarity;
  vector<T> A, st;

  inline int lc(int p) { return (p << 1) + 1; }
  inline int rc(int p) { return (p << 1) + 2; }

  void init(vector<T> v) {
    A = v;
    n = SZ(A);
    polarity = (31 - __builtin_clz(n)) % 2; // impar - or, par - xor
    st.resize(n * 4);
    build(0, 0, n - 1, 0);
  }

  void build(int p, int L, int R, int h) {
    if (L == R) {
      st[p] = A[L];
      return;
    }
    int m = (L + R) >> 1;
    build(lc(p), L, m, h + 1);
    build(rc(p), m + 1, R, h + 1);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }

  T query(int l, int r) { return n == 1 ? A[0] : st[0]; }

  void update(int i, T val, int p, int L, int R, int h) {
    if (L > i || R < i) return;
    if (L == R) {
      st[p] = val;
      return;
    }
    int m = (L + R) >> 1;
    update(i, val, lc(p), L, m, h + 1);
    update(i, val, rc(p), m + 1, R, h + 1);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }
  void update(int i, T val) { update(i, val, 0, 0, n - 1, 0); }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  
  n = 1 << n;
  vi a(n);
  for (auto &ai : a) {
    cin >> ai;
  }

  SegTree<int> st;
  st.init(a);

  while (m--) {
    int p, b;
    cin >> p >> b;
    st.update(p - 1, b);

    cout << st.query(0, n - 1) << ENDL;
  }

  return 0;
}