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

constexpr int maxn = 1e5 + 5, INF = 1e6;

int n;
char a[2][maxn];
int memo[maxn][3][3][3][3];

int win(int x) {
  return x >= 2;
}

int vote(int i, int j) {
  return a[i][j] == 'A';
}

int dp(int i, int u, int vu, int d, int vd) {
  if (i == n) return !u && !d ? 0 : -INF;
  int &ans = memo[i][u][vu][d][vd];
  if (~ans) return ans;
  ans = -INF;
  if (!u) {
    if (d) {
      if (d == 2) {
        ans = max(ans, win(vd + vote(1, i)) + dp(i + 1, 1, vote(0, i), 0, 0));
      } else {
        ans = max(ans, dp(i + 1, 1, vote(0, i), d + 1, vd + vote(1, i)));
        ans = max(ans, win(vd + vote(0, i) + vote(1, i)) + dp(i + 1, 0, 0, 0, 0));
      }
    } else {
      ans = max(ans, dp(i + 1, 1, vote(0, i), 1, vote(1, i)));
      ans = max(ans, dp(i + 1, 2, vote(0, i) + vote(1, i), 0, 0));
      ans = max(ans, dp(i + 1, 0, 0, 2, vote(0, i) + vote(1, i)));
    }
  }
  if (!d && u) {
    if (u == 2) {
      ans = max(ans, win(vu + vote(0, i)) + dp(i + 1, 0, 0, 1, vote(1, i)));
    } else {
      ans = max(ans, dp(i + 1, u + 1, vu + vote(0, i), 1, vote(1, i)));
      ans = max(ans, win(vu + vote(0, i) + vote(1, i)) + dp(i + 1, 0, 0, 0, 0));
    }
  }
  if (u && d) {
    if (u == 2 && d == 2) {
      ans = max(ans, win(vu + vote(0, i)) + win(vd + vote(1, i)) + dp(i + 1, 0, 0, 0, 0));
    } else if (u == 2) {
      ans = max(ans, win(vu + vote(0, i)) + dp(i + 1, 0, 0, d + 1, vd + vote(1, i)));
    } else if (d == 2) {
      ans = max(ans, win(vd + vote(1, i)) + dp(i + 1, u + 1, vu + vote(0, i), 0, 0));
    } else {
      ans = max(ans, dp(i + 1, u + 1, vu + vote(0, i), d + 1, vd + vote(1, i)));
    }
  }
  return ans;
}

void solve(int test_case) {
  cin >> n;
  FOR (i, 0, 2) FOR (j, 0, n) cin >> a[i][j];
  FOR (i, 0, n) FOR (j, 0, 3) FOR (k, 0, 3) FOR (l, 0, 3) FOR (m, 0, 3) memo[i][j][k][l][m] = -1;
  cout << dp(0, 0, 0, 0, 0) << ENDL;
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