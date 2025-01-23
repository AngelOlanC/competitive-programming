#include <bits/stdc++.h>
using namespace std;

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
 * Descripcion: Estructura de conjuntos disjuntos con la
 * capacidad de regresar a estados anteriores.
 * Si no es necesario, ignorar st, time() y rollback().
 * Uso: int t = uf.time(); ...; uf.rollback(t)
 * Tiempo: O(log n)
 */

struct DSU {
  vector<int> e;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};


void solve(int test_case) {
  int n;
  cin >> n;
  vi a(n);
  for (auto &ai : a) cin >> ai;

  DSU dsu;
  dsu.init(n);

  vector<pi> ans(n - 1);
  ROF (i, n, 1) {
    vi lst(i, -1);
    FOR (j, 0, n) {
      int &k = lst[a[j] % i];
      if (~k && dsu.get(j) != dsu.get(k)) {
        dsu.join(j, k);
        ans[i - 1] = {j, k};
        break;
      }
      k = j;
    }
  }
  cout << "YES" << ENDL;
  for (auto &[x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}