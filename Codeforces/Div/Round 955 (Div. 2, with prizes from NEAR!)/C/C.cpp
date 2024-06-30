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

void solve(int t) {
  int n, l, r;
  cin >> n >> l >> r;

  vector<ll> a(n);
  for (auto &ai : a) {
    cin >> ai;
  }

  vector<ll> p(n + 1, 0);
  FOR (i, 1, n + 1) {
    p[i] = p[i - 1] + a[i - 1];
  }

  vi dp(n + 5, 0);
  ROF (i, n + 1, 1) {
    dp[i] = dp[i + 1];

    int d = lower_bound(p.begin() + i, p.end(), l + p[i - 1]) - p.begin();
    if (d == SZ(p)) {
      continue;
    }
    ll sum = p[d] - p[i - 1];
    if (sum >= l && sum <= r) {
      dp[i] = max(dp[i], 1 + dp[d + 1]);
    }
  }
  cout << dp[1] << ENDL;
} 

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  FOR (i, 0, t) {
    solve(t + 1);  
  }

  return 0;
}