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

bool dp[20][5];
string s;

bool solve_dp(int i, int carry) {
  if (i == SZ(s)) {
    return carry == 0;
  }
  if (i == SZ(s) - 1 && s[i] == '1' && carry == 1) {
    return true;
  }
  if (dp[i][carry]) {
    return false;
  }
  dp[i][carry] = 1;
  int d = s[i] - '0';
  FOR (a, 5, 10) {
    FOR (b, 5, 10) {
      int s = (a + b + carry);
      int new_carry = s / 10;
      if (s % 10 == d) {
        return solve_dp(i + 1, new_carry);
      }
    }
  }
  return false;
}

void solve(int t) {
  cin >> s;
  reverse(ALL(s));

  memset(dp, 0, sizeof dp);

  cout << (solve_dp(0, 0) ? "YES" : "NO") << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;
  FOR (i, 0, t) {
    solve(t + 1);  
  }

  return 0;
}