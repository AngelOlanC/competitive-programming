#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

using i64 = long long;
inline int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

constexpr int N = 1 << 10;

int n, m;
int g[N][N], dp[N], pr[N];
vector<pair<int, int>> ways[N];

void f(int i, int m1, int m2) {
  if (i == n) {
    ++g[m1][m2];
    return;
  }
  f(i + 1, m1 | (1 << i), m2);
  f(i + 1, m1, m2 | (1 << i));
  if (i + 2 <= n) {
    f(i + 2, m1, m2);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  f(0, 0, 0);

  for (int i = (1 << n) - 1; i >= 0; --i) {
    for (int j = (1 << n) - 1; j >= 0; --j) {
      if (g[i][j]) {
        ways[i].emplace_back(j, g[i][j]);
      }
    }
  }

  pr[0] = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = (1 << n) - 1; j >= 0; --j) {
      dp[j] = 0;
      for (auto [k, x]: ways[j]) {
        dp[j] = add(dp[j], mul(pr[k], x));
      }
    }
    for (int j = (1 << n) - 1; j >= 0; --j) {
      pr[j] = dp[j];
    }
  }

  cout << dp[0] << '\n';

  return 0;
}