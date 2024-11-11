#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr i64 INF = 1e18;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int N, K;
  cin >> N >> K;

  vector<int> div(N);
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      ++div[j];
    }
  }

  vector<int> g(N), in_deg(N, 0);
  for (int i = 0; i < N; ++i) {
    g[i] = (i + div[i]) % N;
    ++in_deg[g[i]];
  }

  {
    queue<int> q;
    for (int i = 0; i < N; ++i) {
      if (!in_deg[i]) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      --in_deg[g[u]];
      if (!in_deg[g[u]]) {
        q.push(g[u]);
      }
    }
  }
  
  vector<int> cycle_length(N);
  for (int i = 0; i < N; ++i) {
    if (!in_deg[i]) {
      continue;
    }
    int v = g[i], length = 1;
    while (v != i) {
      ++length;
      v = g[v];
    }
    v = g[i];
    cycle_length[i] = length;
    while (v != i) {
      in_deg[v] = 0;
      cycle_length[v] = length;
      v = g[v];
    }
  }

  vector<vector<int>> jmp(25, vector<int>(N));
  vector<vector<i64>> sum(25, vector<i64>(N));
  for (int i = 0; i < N; ++i) {
    jmp[0][i] = g[i];
    sum[0][i] = i;
  }
  for (int i = 1; i < 25; ++i) {
    for (int j = 0; j < N; ++j) {
      jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
      sum[i][j] = sum[i - 1][j] + sum[i - 1][jmp[i - 1][j]];
    }
  }

  auto valid = [&](int u) -> bool {
    int d = 0;
    for (int i = 24; i >= 0; --i) {
      if (!cycle_length[jmp[i][u]]) {
        d += 1 << i;
        u = jmp[i][u];
      }
    }
    ++d;
    u = jmp[0][u];
    return K - d <= cycle_length[u];
  };

  i64 ans = INF, node_ans;
  for (int i = 0; i < N; ++i) {
    if (!valid(i)) {
      continue;
    }
    int u = i;
    i64 curr = 0;
    for (int j = 24; j >= 0; --j) {
      if ((K >> j) & 1) {
        curr += sum[j][u];
        u = jmp[j][u];
      }
    }
    if (curr < ans) {
      ans = curr;
      node_ans = i;
    }
  }
  if (ans == INF) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < K; ++i, node_ans = g[node_ans]) {
    cout << node_ans << ' ';
  }
  cout << '\n';

  return 0;
}