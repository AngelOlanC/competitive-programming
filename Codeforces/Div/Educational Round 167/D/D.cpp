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

constexpr int maxn = 1000000 + 5;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  
  vector<ll> a(n), b(n), c(m);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }
  for (auto &x : c) {
    cin >> x;
  }

  vi p(n);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) { return a[i] < a[j]; });

  auto dif = [&](int i) -> int {
    return a[i] - b[i]; 
  };

  a.pb(maxn * 10), b.pb(-maxn);
  int ptr = 0, min_idx = n;
  vector<ll> dp(maxn, 0);
  FOR (i, 1, maxn) {
    while (ptr < n && a[p[ptr]] <= i) {
      int j = p[ptr];
      // cout << "processsing " << j << ' ' << dif(j) << ' ' << dif(min_idx) << ENDL;
      if (dif(j) < dif(min_idx)) {
        min_idx = j;
      }
      ptr++;
    }
    if (min_idx == n) {
      continue;
    }
    int d = dif(min_idx);
    int k = (i - a[min_idx] + d) / d;
    k += i - k * d < 0;
    // cout << "dp " << i << ' ' << min_idx << ' ' << k << ' ' << d << ' ' << dp[i - k * d] << ENDL; 
    dp[i] = 2 * k + dp[i - k * d];
  }

  // FOR (i, 0, 20) {
  //   cout << i << ' ' << dp[i] << ENDL;
  // }

  ll ans = 0;
  for (auto &x : c) {
    // sumar la bajada y dp[bajado]
    if (x < maxn) {
      ans += dp[x];
      continue;
    }
    int d = dif(min_idx);
    int k = (x - a[min_idx] + d) / d;
    k += x - k * d < 0;
    ans += 2ll * k + dp[x - k * d];
  }
  cout << ans << ENDL;

  return 0;
}