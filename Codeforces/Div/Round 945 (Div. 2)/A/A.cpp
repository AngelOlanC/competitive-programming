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

constexpr int INF = 1e6;
int dp[35][35][35];

int solve(int a, int b, int c) {
  if (!a && !b && !c) {
    return 0;
  }
  if (min({a, b, c}) < 0) {
    return -INF;
  }
  int &ans = dp[a][b][c];
  if (ans != -1) {
    return ans;
  }
  ans = -INF;
  ans = max(1 + solve(a - 1, b - 1, c), 1 + solve(a - 1, b, c - 1));
  ans = max(ans, 1 + solve(a, b - 1, c - 1));
  ans = max(ans, solve(a - 2, b, c));
  ans = max(ans, solve(a , b - 2, c));
  ans = max(ans, solve(a, b, c - 2));
  return ans;
}

void solve(int t) {
  int a, b, c;
  cin >> a >> b >> c;

  memset(dp, -1, sizeof dp);
  int ans = solve(a, b, c);
  cout << (ans < 0 ? -1 : ans) << ENDL;
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