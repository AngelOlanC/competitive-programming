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

constexpr int maxn = 1000 + 5;

int dp[maxn][maxn];
int a[maxn];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, c;
  cin >> c >> n;

  FOR (i, 0, n) {
    cin >> a[i];
  }

  dp[0][0] = 1;
  FOR (i, 0, n) {
    ROF (j, c + 1, 0) {
      ROF (k, c + 1, 0) {
        if (j - a[i] >= 0) {
          dp[j][k] |= dp[j - a[i]][k];
        }
        if (k - a[i] >= 0) {
          dp[j][k] |= dp[j][k - a[i]];
        }
      }
    }
  }

  int j_ans = 0, k_ans = 0;
  FOR (j, 0, c + 1) {
    FOR (k, 0, c + 1) {
      if (dp[j][k] && (j + k > j_ans + k_ans || (j + k == j_ans + k_ans && abs(j - k) < abs(j_ans - k_ans)))) {
        j_ans = j;
        k_ans = k;
      }
    }
  }
  cout << max(j_ans, k_ans) << ' ' << min(j_ans, k_ans) << ENDL;

  return 0;
}