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

constexpr int MOD = 998244353;

template <class T>
class LazySegmentTree {
 private:
  int n;
  const T neutral = 0;  // Cambiar segun la operacion
  vector<T> A, st, lazy;

  inline int l(int p) { return (p << 1) + 1; }  // ir al hijo izquierdo
  inline int r(int p) { return (p << 1) + 2; }  // ir al hijo derecho

  // Cambiar segun la operacion
  T merge(T a, T b) {
    return (a + b) % MOD;
  }

  // Nota: Si se utiliza para el minimo o maximo de un rango no se le agrega el (end - start + 1)
  void propagate(int index, int start, int end, T dif) {
    st[index] += (end - start + 1) * dif;
    if (start != end) {
      lazy[l(index)] += dif;
      lazy[r(index)] += dif;
    }
    lazy[index] = 0;
  }

  void add(int index, int start, int end, int i, int j, T val) {
    if (lazy[index]) {
      propagate(index, start, end, lazy[index]);
    }

    if ((end < i) || (start > j))
      return;

    if (start >= i && end <= j) {
      propagate(index, start, end, val);
      return;
    }
    int mid = (start + end) / 2;

    add(l(index), start, mid, i, j, val);
    add(r(index), mid + 1, end, i, j, val);

    st[index] = merge(st[l(index)], st[r(index)]);
  }

  T query(int index, int start, int end, int i, int j) {
    if (lazy[index]) {
      propagate(index, start, end, lazy[index]);
    }

    if (end < i || start > j)
      return neutral;
    if ((i <= start) && (end <= j))
      return st[index];

    int mid = (start + end) / 2;

    return merge(query(l(index), start, mid, i, j), query(r(index), mid + 1, end, i, j));
  }

 public:
  LazySegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n) {}
  void add(int i, int j, T val) { add(0, 0, n - 1, i, j, val); }  // [i, j]
  T query(int i, int j) { return query(0, 0, n - 1, i, j); }      // [i, j]
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  int a[n], b[n];
  FOR (i, 0, n) {
    cin >> a[i];
  }
  
  LazySegmentTree<ll> sta(n), stb(n), str(n);

  FOR (i, 0, n) {
    cin >> b[i];

    sta.add(i, i, a[i]);
    stb.add(i, i, b[i]);
    str.add(i, i, 1ll * a[i] * b[i]);
  }

  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l, --r;

    if (t == 3) {
      cout << str.query(l, r) << ENDL;
      continue;
    }

    int x;
    cin >> x;
    if (t == 1) {
      ll v = stb.query(l, r);
      cout << " A" << v << ENDL;
      str.add(l, r, v * x / (r - l + 1));
      sta.add(l, r, x);
      continue;
    }
    ll v = sta.query(l, r);
    cout << " B" << v << ENDL;
    str.add(l, r, v * x / (r - l + 1));
    stb.add(l, r, x);
  }

  return 0;
}