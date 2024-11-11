#include<bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0, last = -1; i < n; ++i) {
    int x;
    cin >> x;
    if (x != last) {
      last = x;
      a.push_back(x);
    }
  }
  n = a.size();
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  int m;
  for(int i = m = 0; i < n; ++i) {
    if (!i || b[i] > b[m - 1]) {
      b[m++] = b[i];
    }
  }
  vector<int> cnt(n + 5);
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(b.begin(), b.begin() + m, a[i]) - b.begin();
    ++cnt[a[i]];
  }
  vector<vector<int>> g(n + 5);
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] + 1 == a[i + 1]) {
      g[a[i]].push_back(i);
    }
  }
  vector<bool> vis(n + 5), mg(n + 5);
  auto dfs = [&](auto self, int u, int p) -> bool {
    if (g[u].empty()) {
      return false;
    }
    for (auto &v: g[u]) {
      if (v != p && (!vis[v + 1] || cnt[u + 1] == 1)) {
        mg[v] = vis[v] = vis[v + 1] = 1;
        if (p != -1) {
          mg[p] = 0;
        }
        return true;
      }
    }
    for (auto &v: g[u]) {
      if (v != p && self(self, u + 1, v + 1)) {
        mg[v] = vis[v] = vis[v + 1] = 1;
        if (p != -1) {
          mg[p] = 0;
        }
        return true;
      }
    }
    return false;
  };
  int ans = n - 1;
  for (int i = m - 1; i >= 0; --i) {
    ans -= dfs(dfs, i, -1);
  }
  cout << ans << '\n';
}