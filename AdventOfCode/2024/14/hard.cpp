#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  const int N = 103, M = 101;
  
  string line;
  vector<tuple<int, int, int, int>> robots;
  while (getline(cin, line)) {
    stringstream ss(line);
    char aux_c;
    int px, py, vx, vy;
    ss >> aux_c >> aux_c >> px >> aux_c >> py >> aux_c >> aux_c >> vx >> aux_c >> vy;
    robots.emplace_back(py, px, vy % N, vx % M);
  }

  vector<int> cnt(4);
  vector<vector<int>> at_pos(N, vector<int>(M));
  for (int t = 1; t < 1000000000; ++t) {
    for (auto &[pi, pj, vi, vj] : robots) {
      pi = (pi + vi + N) % N;
      pj = (pj + vj + M) % M;
      ++at_pos[pi][pj];
    }
    bool good = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (at_pos[i][j] > 1) {
          good = false;
          break;
        }
      }
      if (!good) {
        break;
      }
    }
    if (good) {
      cout << t << '\n';
      return 0;
    }
    for (auto &[pi, pj, vi, vj] : robots) {
      --at_pos[pi][pj];
    }
  }
}