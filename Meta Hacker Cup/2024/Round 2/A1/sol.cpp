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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<ll> nums;
  for (int k = 0; k < 9; ++k) {
    for (int i = 1; i < 10 - k; ++i) {
      ll x = 0;
      int d = i;
      for (int l = 0; l < k; ++l, ++d) {
        x *= 10;
        x += d; 
      }
      while (d >= i) {
        x *= 10;
        x += d;
        --d;
      }
      nums.pb(x);
    }
  }

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    ll a, b, m;
    cin >> a >> b >> m;
    int ans = 0;
    for (auto &x : nums) ans += x >= a && x <= b && x % m == 0;
    cout << "Case #" << tc << ": " << ans << ENDL;
  }

  return 0;
}