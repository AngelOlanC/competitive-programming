#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 1e9 + 7, INV2 = ((MOD - 1) >> 1) + 1;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

using i64 = long long;
inline int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

int dp[62626];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  int gauss = n * (n + 1) >> 1;
  if (gauss & 1) {
    cout << 0 << '\n';
    return 0;
  }

  dp[0] = dp[1] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = gauss >> 1; j > i; --j) {
      dp[j] = add(dp[j], dp[j - i - 1]);
    }
  }
  cout << mul(dp[gauss >> 1], INV2) << '\n';

  return 0;
}