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

constexpr ll MOD = 998244353;

void solve() {
  ll w, g, l;
  cin >> w >> g >> l;
  w %= MOD, g %= MOD, l %= MOD;
  ll a = (l * 2 + 1) % MOD, b = (w - g + MOD) % MOD;
  ll ans = a * b % MOD;
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  FOR (i, 1, t + 1) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}