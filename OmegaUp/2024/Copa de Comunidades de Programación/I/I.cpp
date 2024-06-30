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

/**
 * Descripcion: arbol de segmentos, bastante poderoso para
 * realizar consultas de rango y actualizaciones de punto,
 * se puede utilizar cualquier operacion conmutativa, es decir,
 * aquella en donde el orden de evaluacion no importe: suma,
 * multiplicacion, XOR, OR, AND, MIN, MAX, etc.
 * Tiempo: O(n log n) en construccion y O(log n) por consulta
 */
#define NEUT 1
#define oper(a, b) (a * b)
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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vi a(n);
  for (auto &ai : a) {
    cin >> ai;
    if (ai > 0) {
      ai = 1;
    } else if (ai < 0) {
      ai = -1;
    }
  }

  SegTree<int> st;
  st.init(a);

  while (q--) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    if (c == 'C') {
      if (b > 0) {
        b = 1;
      } else if (b < 0) {
        b = -1;
      }
      st.update(a - 1, b);
      continue;
    }
    int x = st.query(a - 1, b - 1);
    if (x == 0) {
      cout << 0 << ENDL;
    } else if (x > 0) {
      cout << "+" << ENDL;
    } else {
      cout << "-" << ENDL;
    }
  }  

  return 0;
}