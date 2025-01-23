#include <bits/stdc++.h>
#include <mutex>
#include <thread>
using namespace std;

constexpr int DI[4] = {-1, 0, 1, 0}, DJ[4] = {0, 1, 0, -1};
int n, m;
vector<string> maze;
tuple<int, int, int> guard_pos;

bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

mutex mut;

void advance(int &i, int &j, int &dir, int blocked_i, int blocked_j) {
  int ii = i + DI[dir], jj = j + DJ[dir];
  if ((valid(ii, jj) && maze[ii][jj] == '#') || (ii == blocked_i && jj == blocked_j)) {
    dir = (dir + 1) % 4;
  } else {
    i = ii;
    j = jj;
  }
}

void evaluate(int blocked_i, int blocked_j, int &ans) {
  auto [guard_i, guard_j, guard_dir] = guard_pos;
  int slow_i = guard_i, slow_j = guard_j, slow_dir = guard_dir;
  int fast_i = guard_i, fast_j = guard_j, fast_dir = guard_dir;
  while (valid(fast_i, fast_j)) {
    advance(slow_i, slow_j, slow_dir, blocked_i, blocked_j);
    advance(fast_i, fast_j, fast_dir, blocked_i, blocked_j);
    advance(fast_i, fast_j, fast_dir, blocked_i, blocked_j);
    if (valid(fast_i, fast_j) && slow_i == fast_i && slow_j == fast_j && slow_dir == fast_dir) {
      ++ans;
      return;
    }
  }
}


void work(vector<pair<int, int>> path, int start, int &ans) {
  for (int i = start; i < path.size(); i += 6) {
    evaluate(path[i].first, path[i].second, ans);
  }
}

vector<pair<int, int>> get_path() {
  auto [i, j, dir] = guard_pos;
  vector<pair<int, int>> path;
  while (valid(i, j)) {
    path.push_back({i, j});
    advance(i, j, dir, -1, -1);
  }
  sort(path.begin(), path.end());
  path.erase(unique(path.begin(), path.end()), path.end());
  return path;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string line;
  while (getline(cin, line)) {
    maze.push_back(line);
  }
  n = maze.size();
  m = maze[0].size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == '^') {
        guard_pos = {i, j, 0};
      }
    }
  }
  vector<pair<int, int>> path = get_path();
  int ans = 0;
  thread t0(work, path, 0);
  thread t1(work, path, 1);
  thread t2(work, path, 2);
  thread t3(work, path, 3);
  thread t4(work, path, 4);
  thread t5(work, path, 5);
  t0.join();
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  cout << ans << '\n';
  return 0;
}