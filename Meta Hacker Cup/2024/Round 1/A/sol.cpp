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

using ld = long double;

void solve() {
  int n;
  cin >> n;
  vi a(n), b(n);
  FOR (i, 0, n) cin >> a[i] >> b[i];
  ld lo = 0, hi = 1e18;
  FOR (i, 0, n) {
    ld l = (ld)(i + 1) / b[i], h = (a[i] == 0 ? 1e18 : (ld)(i + 1) / a[i]);
    lo = max(lo, l);
    hi = min(hi, h);
  }
  if (lo > hi) {
    cout << -1 << ENDL;
    return;
  }
  cout << lo << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << setprecision(9) << fixed;

  int t;
  cin >> t;
  FOR (i, 1, t + 1) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}