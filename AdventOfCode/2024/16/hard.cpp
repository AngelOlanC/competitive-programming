#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int DI[4] = {-1, 0, 1, 0}, DJ[4] = {0, 1, 0, -1};

vector<vector<vector<int>>> dijkstra_start(int si, int sj, vector<string>& maze) {
  int n = (int)maze.size(), m = (int)maze[0].size();
  vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(4, 1e9)));
  priority_queue<tuple<int, int, int, int>> pq;
  d[si][sj][1] = 0;
  pq.emplace(0, si, sj, 1);
  while (!pq.empty()) {
    auto [w, i, j, k] = pq.top();
    pq.pop();
    w = -w;

    if (w + 1000 < d[i][j][(k + 1) % 4]) {
      d[i][j][(k + 1) % 4] = w + 1000;
      pq.emplace(-d[i][j][(k + 1) % 4], i, j, (k + 1) % 4);
    }

    if (w + 1000 < d[i][j][(k + 3) % 4]) {
      d[i][j][(k + 3) % 4] = w + 1000;
      pq.emplace(-d[i][j][(k + 3) % 4], i, j, (k + 3) % 4);
    }

    int ii = i + DI[k], jj = j + DJ[k];
    if (maze[ii][jj] != '#' && w + 1 < d[ii][jj][k]) {
      d[ii][jj][k] = w + 1;
      pq.emplace(-d[ii][jj][k], ii, jj, k);
    }
  }
  return d;
}

vector<vector<vector<int>>> dijkstra_end(int ei, int ej, vector<string>& maze) {
  int n = (int)maze.size(), m = (int)maze[0].size();
  vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(4, 1e9)));
  priority_queue<tuple<int, int, int, int>> pq;
  d[ei][ej][0] = 0;
  d[ei][ej][1] = 0;
  d[ei][ej][2] = 0;
  d[ei][ej][3] = 0;
  pq.emplace(0, ei, ej, 0);
  pq.emplace(0, ei, ej, 1);
  pq.emplace(0, ei, ej, 2);
  pq.emplace(0, ei, ej, 3);
  while (!pq.empty()) {
    auto [w, i, j, k] = pq.top();
    pq.pop();
    w = -w;

    if (w + 1000 < d[i][j][(k + 1) % 4]) {
      d[i][j][(k + 1) % 4] = w + 1000;
      pq.emplace(-d[i][j][(k + 1) % 4], i, j, (k + 1) % 4);
    }

    if (w + 1000 < d[i][j][(k + 3) % 4]) {
      d[i][j][(k + 3) % 4] = w + 1000;
      pq.emplace(-d[i][j][(k + 3) % 4], i, j, (k + 3) % 4);
    }

    int ii = i + DI[(k + 2) % 4], jj = j + DJ[(k + 2) % 4];
    if (maze[ii][jj] != '#' && w + 1 < d[ii][jj][k]) {
      d[ii][jj][k] = w + 1;
      pq.emplace(-d[ii][jj][k], ii, jj, k);
    }
  }
  return d;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> maze;
  string line;
  while (cin >> line) {
    maze.push_back(line);
  }

  int n = (int)maze.size(), m = (int)maze[0].size();

  int ei, ej, si, sj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == 'E') {
        ei = i;
        ej = j;
      }
      if (maze[i][j] == 'S') {
        si = i;
        sj = j;
      }
    }
  }

  vector<vector<vector<int>>> d_st = dijkstra_start(si, sj, maze);
  vector<vector<vector<int>>> d_en = dijkstra_end(ei, ej, maze);

  int mn_end = min({
    d_st[ei][ej][0],
    d_st[ei][ej][1],
    d_st[ei][ej][2],
    d_st[ei][ej][3]
  });

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == '#') {
        continue;
      }
      for (int k = 0; k < 4; ++k) {
        if (d_st[i][j][k] + d_en[i][j][k] == mn_end) {
          ++ans;
          break;
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}