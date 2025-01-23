#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  vector<int> c(n);
  for (int& x : c) {
    cin >> x;
  }

  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (int y : c) {
      if (y <= i) {
        dp[i] = add(dp[i], dp[i - y]);
      }
    }
  }
  cout << dp[x] << '\n';

  return 0;
}