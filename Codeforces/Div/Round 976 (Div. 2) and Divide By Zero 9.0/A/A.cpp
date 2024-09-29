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
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << ENDL;
    return;
  }
  ll pot = k;
  while (pot * k <= n) pot *= k;
  ll ans = 0;
  while (n) {
    while (pot > n) pot /= k;
    ans += n / pot;
    n %= pot;
  }
  cout << ans << ENDL;
}

signed main() {
  

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    // cout << "t" << test_case << ENDL;
    solve(test_case + 1);
  }

  return 0;
}