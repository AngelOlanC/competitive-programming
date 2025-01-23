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

void solve(int test_case) {
  int n, m;
  cin >> n >> m;
  vector<vi> b(n);
  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    b[--u].pb(--v);
  }
  vi dp(n, 1e9);
  dp[0] = 0;
  FOR (u, 0, n - 1) {
    dp[u + 1] = min(dp[u + 1], dp[u] + 1);
    for (auto &v : b[u]) dp[v] = min(dp[v], dp[u] + 1);
  }
  vi p(n + 1);
  FOR (u, 0, n) {
    for (auto &v : b[u]) {
      int r = v - 2 - dp[u];
      if (u < r) {
        p[u + 1]++;
        p[r + 1]--;
      }
    }
  }
  FOR (u, 0, n - 1) {
    p[u + 1] += p[u];
    cout << (p[u] == 0);
  }
  cout << ENDL;
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