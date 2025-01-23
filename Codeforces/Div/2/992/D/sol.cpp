#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, int& curr, vector<vector<int>>& g, vector<int>& ans, vector<bool>& prime) {
  ans[u] = curr++;
  for (int v : g[u]) {
    if (v != p) {
      while (prime[curr - ans[u]]) {
        ++curr;
      }
      dfs(v, u, curr, g, ans, prime);
    }
  }
}

void solve(vector<bool>& prime) {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> ans(n);
  int curr = 1;
  dfs(0, -1, curr, g, ans, prime);
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int N = 5e5;
  vector<bool> prime(5e5, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i < N; ++i) {
    if (!prime[i]) {
      continue;
    }
    for (int j = 2 * i; j < N; j += i) {
      prime[j] = false;
    }
  }
  int tc;
  cin >> tc;
  while (tc--) {
    solve(prime);
  }

  return 0;
}