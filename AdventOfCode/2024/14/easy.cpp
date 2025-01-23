#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string line;
  vector<tuple<int, int, int, int>> robots;
  while (getline(cin, line)) {
    stringstream ss(line);
    char aux_c;
    int px, py, vx, vy;
    ss >> aux_c >> aux_c >> px >> aux_c >> py >> aux_c >> aux_c >> vx >> aux_c >> vy;
    robots.emplace_back(py, px, vy, vx);
  }

  const int N = 103, M = 101;
  vector<int> cnt(4);
  for (auto &[pi, pj, vi, vj] : robots) {
    vi %= N;
    vj %= M;
    for (int t = 0; t < 100; ++t) {
      pi = (pi + vi + N) % N;
      pj = (pj + vj + M) % M;
    }
    if (pi < N / 2) {
      if (pj < M / 2) {
        cnt[0]++;
      } else if (pj > M / 2) {
        cnt[1]++;
      }
    } else if (pi > N / 2) {
      if (pj < M / 2) {
        cnt[2]++;
      } else if (pj > M / 2) {
        cnt[3]++;
      }
    }
  }
  cout << cnt[0] * cnt[1] * cnt[2] * cnt[3] << '\n';
}