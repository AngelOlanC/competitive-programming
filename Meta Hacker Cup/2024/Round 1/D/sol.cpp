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

void solve() {
  string s;
  int k;
  cin >> s >> k;
  int n = SZ(s);
  vector<vi> dp(n + 1, vi(10));
  FOR (i, 0, 10) dp[n][i] = 1;
  ROF (i, n, 0) FOR (j, 0, 10) {
    
    FOR (k, (j == 0), 10) {

    }
  }
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