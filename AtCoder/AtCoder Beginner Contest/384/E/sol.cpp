#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int DI[4] = {-1, 0, 1, 0}, DJ[4] = {0, 1, 0, -1};

void process(int i, int j, vector<vector<i64>>& a, vector<vector<bool>>& vis, priority_queue<tuple<i64, int, int>>& pq) {
  int n = (int)a.size(), m = (int)a[0].size();
  for (int dir = 0; dir < 4; ++dir) {
    int ii = i + DI[dir], jj = j + DJ[dir];
    if (ii >= 0 && ii < n && jj >= 0 && jj < m && !vis[ii][jj]) {
      vis[ii][jj] = true;
      pq.emplace(-a[ii][jj], ii, jj);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, x, p, q;
  cin >> n >> m >> x >> p >> q;
  --p;
  --q;

  vector<vector<i64>> a(n, vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  vector<vector<bool>> vis(n, vector<bool>(m));
  priority_queue<tuple<i64, int, int>> pq;
  vis[p][q] = true;
  i64 S = a[p][q];
  process(p, q, a, vis, pq);
  while (!pq.empty()) {
    auto [t, i, j] = pq.top();
    pq.pop();
    t = -t;
    if ((S % x == 0 && t >= S / x) || (S % x != 0 && t > S / x)) {
      break;
    }
    S += t;
    process(i, j, a, vis, pq);
  }
  cout << S << '\n';
}