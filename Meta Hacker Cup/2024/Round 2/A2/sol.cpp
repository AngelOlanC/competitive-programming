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

vector<ll> nums;

void gen(int i, int d, int k, ll x) {
  if (i == 2 * k + 1) {
    nums.pb(x);
    return;
  }
  if (i < k) {
    while (d <= 9) {
      gen(i + 1, d, k, x * 10 + d);
      ++d;
    }
    return;
  }
  if (i == k) {
    ++d;
    while (d <= 9) {
      gen(i + 1, d - 1, k, x * 10 + d);
      ++d;
    }
    return;
  }
  for (int dd = 1; dd <= d; ++dd) {
    gen(i + 1, dd, k, x * 10 + dd);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  for (int i = 1; i <= 9; ++i) nums.pb(i); 
  for (int k = 1; k < 9; ++k) gen(0, 1, k, 0ll);  

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    ll a, b, m;
    cin >> a >> b >> m;
    int ans = 0;
    auto it = lower_bound(ALL(nums), a);
    while (it != nums.end() && *it <= b) {
      if (*it % m == 0) ++ans;
      ++it;
    }
    cout << "Case #" << tc << ": " << ans << ENDL;
  }

  return 0;
}