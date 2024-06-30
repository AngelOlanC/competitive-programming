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

#define N 1010

constexpr ll MOD = 1e9 + 7;

int n, k;
int p[N];
ll dp[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  FOR (i, 1, n + 1) {
    cin >> p[i];
  }

  ll s = 0;
  FOR (i, 1, n + 1) {
    dp[i] = 1;
    FOR (j, p[i], i) {
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
    dp[i]++;
    s = (s + dp[i]) % MOD;
  }
  cout << s << ENDL;

  return 0;
}