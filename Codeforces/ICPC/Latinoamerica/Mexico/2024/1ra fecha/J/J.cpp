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

int N, K;
int dp[501][501][501];
string s;

int solve(int l, int r, int k) {
  if (!k) {
    return 0;
  }
  if (l > r) {
    return 1e7;
  }
  if (k == 1) {
    return 0;
  }
  if (l == r) {
    return 1e7;
  }
  int &ans = dp[l][r][k];
  if (ans != -1) {
    return ans;
  }
  ans = 1e7;
  if (s[l] == s[r]) {
    ans = solve(l + 1, r - 1, k - 2);
  }
  ans = min(ans, solve(l + 1, r - 1, k - 2) + 1);
  ans = min(ans, solve(l + 1, r, k));
  ans = min(ans, solve(l, r - 1, k));
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> K >> s;

  memset(dp, -1, sizeof dp);

  cout << solve(0, N - 1, K) << ENDL;

  return 0;
}