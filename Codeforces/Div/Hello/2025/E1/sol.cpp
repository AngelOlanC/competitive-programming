#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void bfs(vector<vector<int>>& g, vector<int>& d, int st) {
  d[st] = 0;
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> weights;
  vector<tuple<int, int, int>> e(m);
  for (auto &[u, v, w] : e) {
    cin >> u >> v >> w;
    --u;
    --v;
    weights.push_back(w);
  }

  sort(weights.begin(), weights.end());
  weights.erase(unique(weights.begin(), weights.end()), weights.end());

  vector<vector<vector<int>>> g((int)weights.size(), vector<vector<int>>(n));
  for (auto [u, v, w] : e) {
    for (int i = 0; i < (int)weights.size() && w >= weights[i]; ++i) {
      g[i][u].push_back(v);
      g[i][v].push_back(u);
    }
  }

  vector<vector<vector<int>>> d((int)weights.size(), vector<vector<int>>(n, vector<int>(n, -1)));
  for (int i = 0; i < (int)g.size(); ++i) {
    for (int u = 0; u < n; ++u) {
      bfs(g[i], d[i][u], u);
      // cout << "d with " << i << ' ' << u << '\n';
      // for (int v = 0; v < n; ++v) {
      //   cout << d[i][u][v] << ' ';
      // }
      // cout << '\n';
    }
  }

  while (q--) {
    int a, b, k;
    cin >> a >> b >> k;
    --a;
    --b;

    int l = 0, r = (int)weights.size() - 1;
    while (l < r) {
      int m = (l + r + 1) >> 1;
      if (d[m][b][a] < k) {
        r = m - 1;
      } else {
        l = m;
      }
    }
    cout << weights[l] << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}