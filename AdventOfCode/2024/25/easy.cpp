#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int p[7][7][7][7][7];
  memset(p, 0, sizeof p);

  vector<vector<int>> locks, keys;
  while (true) {
    string line;
    vector<string> maze;
    while (getline(cin, line) && !line.empty()) {
      maze.push_back(line);
    }
    if (maze.empty()) {
      break;
    }
    if (maze[0][0] == '#') {
      vector<int> h(5);
      for (int j = 0; j < 5; ++j) {
        int i = 1;
        while (maze[i][j] == '#') {
          ++i;
        }
        h[j] = i - 1;
      }
      locks.push_back(h);
      continue;
    }
    vector<int> h(5);
    for (int j = 0; j < 5; ++j) {
      int i = 6;
      while (maze[i][j] == '#') {
        --i;
      }
      h[j] = 5 - i;
    }
    ++p[h[0]][h[1]][h[2]][h[3]][h[4]];
  }

  for (int i = 1; i < 7; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 7; ++k) {
        for (int l = 0; l < 7; ++l) {
          for (int m = 0; m < 7; ++m) {
            p[i][j][k][l][m] += p[i - 1][j][k][l][m];
          }
        }
      }
    }
  }

  for (int i = 0; i < 7; ++i) {
    for (int j = 1; j < 7; ++j) {
      for (int k = 0; k < 7; ++k) {
        for (int l = 0; l < 7; ++l) {
          for (int m = 0; m < 7; ++m) {
            p[i][j][k][l][m] += p[i][j - 1][k][l][m];
          }
        }
      }
    }
  }

  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 1; k < 7; ++k) {
        for (int l = 0; l < 7; ++l) {
          for (int m = 0; m < 7; ++m) {
            p[i][j][k][l][m] += p[i][j][k - 1][l][m];
          }
        }
      }
    }
  }

  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 7; ++k) {
        for (int l = 1; l < 7; ++l) {
          for (int m = 0; m < 7; ++m) {
            p[i][j][k][l][m] += p[i][j][k][l - 1][m];
          }
        }
      }
    }
  }

  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 7; ++k) {
        for (int l = 0; l < 7; ++l) {
          for (int m = 1; m < 7; ++m) {
            p[i][j][k][l][m] += p[i][j][k][l][m - 1];
          }
        }
      }
    }
  }

  int ans = 0;
  for (auto& lock : locks) {
    vector<int> v(5);
    for (int j = 0; j < 5; ++j) {
      v[j] = 6 - lock[j] - 1;
    }
    if (*min_element(v.begin(), v.end()) >= 0) {
      ans += p[v[0]][v[1]][v[2]][v[3]][v[4]];
    }
  }
  cout << ans << '\n';

  return 0;
}