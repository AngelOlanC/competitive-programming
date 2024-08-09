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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k, lc, pc, lm, pm, t, d;
  cin >> n >> k >> lc >> pc >> lm >> pm >> t >> d;
  --k;
  ll w = 0, r = 0;
  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
    w += min(d, max(0, a[i] - lm));
    r += max(0, lm - a[i]);
  }
  sort(ALL(a));
  auto upd = [&](int i, int driver) -> void {
    w -= min(d, max(0, a[i] - lm));
    r -= max(0, lm - a[i]);
    if (!driver) {
      w += min(d, a[i] - 1);
      return;
    } 
    r += max(0, lc - a[i]);
    w += min(d, max(0, a[i] - lc));
  };
  // cout << w << ' ' << r << ENDL;
  ll ans = INF;
  if (lm - a[0] <= d && w >= r) ans = 1ll * t * r + 1ll * n * pm; 
  for (int i = 1; (i - 1) * (k + 1) < n && lc - a[n - i] <= d; i++) {
    FOR (j, (i - 1) * k, min(i * k, n - i)) upd(j, 0);
    upd(n - i, 1);
    // cout << i << ' ' << w << ' ' << r << ENDL;
    if ((i * (k + 1) == n || i * k >= n || lm - a[i * k] <= d) && w >= r) {
      ans = min(ans, 1ll * i * pc + 1ll * t * r + 1ll * max(0, (n - i * (k + 1))) * pm);
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << ENDL;

  return 0;
}