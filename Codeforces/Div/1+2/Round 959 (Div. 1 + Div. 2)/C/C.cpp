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

void solve(int test_case) {
  int n, x;
  cin >> n >> x;
  vi a(n);
  for (auto &ai : a) cin >> ai;
  a.pb(0);

  vector<ll> dp(n + 2);
  int rp = n;
  ll s = 0;
  ROF (i, n, 0) {
    s += a[i];
    while (s - a[rp] > x) s -= a[rp--];
    dp[i] = rp - i + dp[rp + 1];
  }
  cout << accumulate(ALL(dp), 0LL) << ENDL;
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