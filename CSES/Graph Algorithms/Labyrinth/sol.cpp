#include <bits/stdc++.h>
using namespace std;
constexpr int DI[4] = {-1, 1, 0, 0}, DJ[4] = {0, 0, -1, 1};
constexpr char DIR[4] = {'U', 'D', 'L', 'R'};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  pair<int, int> s, e;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        s = {i, j};
      } else if (a[i][j] == 'B') {
        e = {i, j};
      }
    }
  }
  auto valid = [&](int i, int j) -> bool {
    return i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#';
  };
  vector<vector<int>> dist(n, vector<int>(m, 1e9)), prev(n, vector<int>(m));
  queue<pair<int, int>> q;
  q.push({s.first, s.second});
  dist[s.first][s.second] = 0;
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
  if (dist[e.first][e.second] == 1e9) {
    cout << "NO\n";
    return 0;
  }
  auto [i, j] = e;
  cout << "YES" << '\n';
  cout << dist[i][j] << '\n';
  stack<char> st;
  while (i != s.first || j != s.second) {
    st.push(DIR[prev[i][j] ^ 1]);
    int dir = prev[i][j];
    i = i + DI[dir];
    j = j + DJ[dir];
  }
  while (!st.empty()) {
    cout << st.top();
    st.pop(); 
  }
  cout << '\n';
}