#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

#define N 5005

constexpr int INF = 1 << 28;

int n, m;
int s[N];
double p[N];
int dp[N][N];

int solve(int i, int g) {
  if (g >= m) {
    return INF;
  }
  if (i == n) {
    return 0;
  }
  int &ans = dp[i][g];
  if (~ans) {
    return ans;
  }
  int diff = s[i] != g;
  return ans = min({solve(i, g + 1), 
                    solve(i + 1, g) + diff, 
                    solve(i + 1, g + 1) + diff});
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m;
  FOR (i, 0, n) {
    cin >> s[i] >> p[i];
    s[i]--;
  }

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0); 

  return 0;
}