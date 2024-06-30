#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

#define MAX 100010

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vi a(n), last(MAX, -1);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  vi dp(MAX, 0);
  ROF (i, n, 0) {
    int k = a[i];
    vi divisors;
    for (int j = 2; 1ll * j * j <= k; j++) {
      if (k % j == 0) {
        divisors.pb(j);
      }
      while (k % j == 0) {
        k /= j;
      }
    }
    if (k != 1) {
      divisors.pb(k);
    }
    int ans = 0;
    for (auto &d : divisors) {
      ans = max(ans, 1 + dp[d]);
    }
    for (auto &d : divisors) {
      dp[d] = ans;
    }
  }
  dp[1] = 1;
  
  cout << *max_element(ALL(dp)) << ENDL;

  return 0;
}