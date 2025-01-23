#include <bits/stdc++.h>
// Pura Gente del Coach Moy

using i64 = long long;

const int MOD = 16777216;

int prune(i64 x) {
  return x % MOD;
}

i64 mix(i64 x, i64 y) {
  return x ^ y;
}

int apply(i64 x, i64 y) {
  return prune(mix(x, y));
}

int transform(int x) {
  x = apply(x, x * 64ll);
  x = apply(x, x / 32);
  x = apply(x, x * 2048ll);
  return x;
}

constexpr int INF = 1e9;

int maps[2000][19][19][19][19];

int main() {
  for (int i = 0; i < 2000; ++i) {
    for (int j = 0; j < 19; ++j) {
      for (int k = 0; k < 19; ++k) {
        for (int l = 0; l < 19; ++l) {
          for (int m = 0; m < 19; ++m) {
            maps[i][j][k][l][m] = -INF;
          }
        }
      }
    }
  }
  int x;
  std::vector<std::vector<int>> diff, val;
  while (std::cin >> x) {
    std::vector<int> curr_diff, curr_val = { x % 10 };
    for (int i = 0; i < 2000; ++i) {
      int y = transform(x);
      curr_diff.push_back((y % 10) - (x % 10));
      curr_val.push_back(y % 10);
      x = y;
    }
    val.push_back(curr_val);
    diff.push_back(curr_diff);
  }
  int n = (int)diff.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 3; j < (int)diff[i].size(); ++j) {
      int &x = maps[i][diff[i][j - 3] + 9][diff[i][j - 2] + 9][diff[i][j - 1] + 9][diff[i][j] + 9];
      if (x == -INF) {
        x = val[i][j + 1];
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < 19; ++j) {
    for (int k = 0; k < 19; ++k) {
      for (int l = 0; l < 19; ++l) {
        for (int m = 0; m < 19; ++m) {
          int curr = 0;
          for (int i = 0; i < n; ++i) {
            int x = maps[i][j][k][l][m];
            if (x != -INF) {
              curr += maps[i][j][k][l][m];
            }
          }
          ans = std::max(ans, curr);
        }
      }
    }
  }
  std::cout<< ans << '\n';

  return 0;
}