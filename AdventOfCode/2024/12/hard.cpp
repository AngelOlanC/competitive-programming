#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

constexpr int DI[4] = {-1, 0, 1, 0}, DJ[4] = {0, 1, 0, -1};

int n, m;
vector<string> maze;
vector<vector<bool>> vis;
int area = 0, sides = 0;

bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

vector<vector<vector<bool>>> vis_sides;
void dfs_side(int i, int j, int side) {
  if (vis_sides[i][j][side]) {
    return;
  }
  vis_sides[i][j][side] = true;
  int dir = (side + 1) % 4;
  int ii = i + DI[dir], jj = j + DJ[dir];
  if (!valid(ii, jj) || maze[ii][jj] != maze[i][j]) {
    ++sides;
    dfs_side(i, j, dir);
    return;
  }
  int iii = ii + DI[side], jjj = jj + DJ[side];
  if (!valid(iii, jjj) || maze[iii][jjj] != maze[i][j]) {
    dfs_side(ii, jj, side);
    return;
  }
  ++sides;
  dfs_side(iii, jjj, (side + 3) % 4);
}

void dfs(int i, int j) {
  vis[i][j] = true;
  ++area;
  for (int dir = 0; dir < 4; ++dir) {
    int ii = i + DI[dir], jj = j + DJ[dir];
    if (valid(ii, jj) && !vis[ii][jj] && maze[ii][jj] == maze[i][j]) {
      dfs(ii, jj);
    } else if (!valid(ii, jj) || maze[ii][jj] != maze[i][j]) {
      if (!vis_sides[i][j][dir]) {
        dfs_side(i, j, dir);
      }
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string line;
  while (cin >> line) {
    maze.push_back(line);
    ++n;
  }
  m = maze[0].size();

  vis.assign(n, vector<bool>(m));
  vis_sides.assign(n, vector<vector<bool>>(m, vector<bool>(4)));

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vis[i][j]) {
        continue;
      }
      area = sides = 0;

      dfs(i, j);

      ans += (i64) area * sides;
    }
  }
  cout << ans << '\n';

  return 0;
}