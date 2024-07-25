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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi a(n);
  for (auto &ai : a) cin >> ai;

  sort(ALL(a));

  vector<ll> sd(5005);
  FOR (i, 0, n) {
    FOR (j, 0, i) {
      sd[a[i] - a[j]]++;
    }
  }

  vector<ll> dd(5010);
  FOR (i, 1, 5005) {
    FOR (j, 1, 5005 - i) {
      dd[i + j + 1] += sd[i] * sd[j];
    }
  }

  FOR (i, 2, 5005) dd[i] += dd[i - 1];

  ll up = 0, downsq3 = 1ll * n * (n - 1) / 2;
  FOR (i, 0, n) {
    FOR (j, 0, i) {
      up += dd[a[i] - a[j]];
    }
  }
  double ans = up;
  ans /= downsq3, ans /= downsq3, ans /= downsq3;
  // cout << up << ' ' << downsq3 << ' ';
  cout << setprecision(12) << fixed << ans << ENDL;

  return 0;
}