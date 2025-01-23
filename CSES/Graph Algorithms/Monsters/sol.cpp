#include <bits/stdc++.h>
using namespace std;
constexpr int DI[4] = {-1, 1, 0, 0}, DJ[4] = {0, 0, -1, 1};
constexpr char DIR[4] = {'U', 'D', 'L', 'R'};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  pair<int, int> s;
  vector<pair<int, int>> monsters;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        s = {i, j}; 
      } else if (a[i][j] == 'M') {
        monsters.push_back({i, j});
      }
    }
  }
  auto valid = [&](int i, int j) -> bool {
    return i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#';
  };
  auto bfs = [&](vector<pair<int, int>> s) -> pair<vector<vector<int>>, vector<vector<int>>> {
    vector<vector<int>> dist(n, vector<int>(m, 1e9)), prev(n, vector<int>(m));
    queue<pair<int, int>> q;
    for (auto &[i, j] : s) {
      dist[i][j] = 0;
      q.push({i, j});
    }
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int ii = i + DI[dir], jj = j + DJ[dir];
        if (valid(ii, jj) && dist[i][j] + 1 < dist[ii][jj]) {
          dist[ii][jj] = dist[i][j] + 1;
          prev[ii][jj] = dir ^ 1;
          q.push({ii, jj});
        }
      }
    }
    return {dist, prev};
  };
  auto [dist, prev] = bfs({{s.first, s.second}});
  vector<vector<int>> dist_monsters = bfs(monsters).first;
  auto print_path = [&](int i, int j) -> void {
    stack<char> path;
    while (i != s.first || j != s.second) {
      int dir = prev[i][j];
      path.push(DIR[dir ^ 1]);
      i += DI[dir];
      j += DJ[dir];
    }
    cout << (int)path.size() << '\n';
    while (!path.empty()) {
      cout << path.top();
      path.pop();
    }
    cout << '\n';
  };
  for (int i = 0; i < n; ++i) {
    if (dist[i][0] < dist_monsters[i][0]) {
      cout << "YES\n";
      print_path(i, 0);
      return 0;
    }
    if (dist[i][m - 1] < dist_monsters[i][m - 1]) {
      cout << "YES\n";
      print_path(i, m - 1);
      return 0;
    }
  }
  for (int j = 0; j < m; ++j) {
    if (dist[0][j] < dist_monsters[0][j]) {
      cout << "YES\n";
      print_path(0, j);
      return 0;
    }
    if (dist[n - 1][j] < dist_monsters[n - 1][j]) {
      cout << "YES\n";
      print_path(n - 1, j);
      return 0;
    }
  }
  cout << "NO\n";
}