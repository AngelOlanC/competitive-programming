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

#define N 300010

int n, K;
ll a[N];
ll dp[N][15];

ll solve(int i, int k) {
  if (!k || i >= n) {
    return 0;
  }
  ll &ans = dp[i][k];
  if (ans != -1) {
    return ans;
  }
  ans = solve(i + 1, k);
  ll sum = a[i], minv = a[i];
  FOR (j, i + 1, min(i + k + 1, n)) {
    minv = min(minv, a[j]);
    sum += a[j];
    int d = j - i + 1;
    ans = max(ans, sum - minv * 1ll * d + solve(j + 1, k - d + 1));
  }
  return ans;
}

void solve(int t) {
  cin >> n >> K;
  ll sum = 0;
  FOR (i, 0, n) {
    cin >> a[i];
    sum += a[i];
    FOR (j, 0, 15) {
      dp[i][j] = -1;
    }
  }
  cout << sum - solve(0, K) << ENDL;
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