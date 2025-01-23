#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int N = 20;

int n, x;
int a[N];
pair<int, int> dp[1 << N];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> x;

  for (int& x : a) {
    cin >> x;
  }

  for (int i = (1 << n) - 1; i; --i) {
    dp[i] = {1e9, 0};
  }
  dp[0] = {0, 0};

  for (int i = 1; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        auto [c, r] = dp[i ^ (1 << j)];
        r = -r;
        // cout << "comparo " << i << ' ' << (i ^ (1 << j)) << ' ' << c << ' ' << r << ' ' << a[j];
        if (a[j] <= r) {
          // cout << "menor\n";
          dp[i] = min(dp[i], make_pair(c, -(r - a[j])));
        } else {
          // cout << "mayor\n";
          dp[i] = min(dp[i], make_pair(c + 1, -(x - a[j])));
        }
      }
    }
    // cout << i << ' ' << dp[i].first << ' ' << dp[i].second << '\n';
  }
  cout << dp[(1 << n) - 1].first << '\n'; 

  return 0;
}