#include <bits/stdc++.h>
using namespace std;

constexpr int DI[4] = {-1, 0, 1, 0}, DJ[4] = {0, 1, 0, -1};

void bfs(int si, int sj, vector<vector<bool>>& mat, vector<vector<int>>& d) {
  int n = (int)mat.size();
  queue<pair<int, int>> q;
  d[si][sj] = 0;
  q.emplace(si, sj);
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int ii = i + DI[dir], jj = j + DJ[dir];
      if (mat[ii][jj] && d[ii][jj] == -1) {
        d[ii][jj] = d[i][j] + 1;
        q.emplace(ii, jj);
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vector<bool>> maze;
  int si, sj, ei, ej;
  {
    string line;
    while (cin >> line) {
      int m = (int)line.size();
      vector<bool> row(m);
      for (int j = 0; j < m; ++j) {
        if (line[j] == '#') {
          continue;
        }
        row[j] = true;
        if (line[j] == 'S') {
          si = (int)maze.size();
          sj = j;
        } else if (line[j] == 'E') {
          ei = (int)maze.size();
          ej = j;
        }
      }
      maze.push_back(row);
    }
  }

  int n = (int)maze.size(), m = (int)maze[0].size();

  vector<vector<int>> ds(n, vector<int>(m, -1));
  vector<vector<int>> de(n, vector<int>(m, -1));
  bfs(si, sj, maze, ds);
  bfs(ei, ej, maze, de);

  cout << ds[ei][ej] << '\n';
  cout << n << ' ' << m << '\n';

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ds[i][j] == -1) {
        continue;
      }
      for (int k = 0; k < n; ++k) {
        for (int l = 0; l < m; ++l) {
          if ((i == k && j == l) || de[k][l] == -1) {
            continue;
          }
          int db = abs(i - k) + abs(j - l);
          int nd = ds[i][j] + db + de[k][l];
          if (db <= 20 && ds[ei][ej] - nd >= 100) {
            ++ans;
          }
        }
      }
    }
  }
  cout << ans << '\n';
}