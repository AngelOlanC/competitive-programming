#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int DI[4] = {-1, 0, 1, 0}, DJ[4] = {0, 1, 0, -1};
constexpr int N = 71;

bool reachable(vector<vector<bool>>& bad) {
  vector<vector<int>> dist(N, vector<int>(N, -1));
  queue<pair<int, int>> q;
  dist[0][0] = 0;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int ii = i + DI[dir], jj = j + DJ[dir];
      if (ii >= 0 && ii < N && jj >= 0 && jj < N && !bad[ii][jj] && dist[ii][jj] == -1) {
        dist[ii][jj] = dist[i][j] + 1;
        q.emplace(ii, jj);
      }
    }
  }
  return dist[N - 1][N - 1] != -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vector<bool>> bad(N, vector<bool>(N));

  string line;
  while (cin >> line) {
    stringstream ss(line);
    int x, y;
    char aux_c;
    ss >> x >> aux_c >> y;
    bad[y][x] = true;
    if (!reachable(bad)) {
      cout << x << "," << y << '\n';
      break;
    }
  }

  


  return 0;
}