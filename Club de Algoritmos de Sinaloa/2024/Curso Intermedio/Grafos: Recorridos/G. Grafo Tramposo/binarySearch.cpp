#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

#define N 1005
#define MAX 1000005

int n, m;
vector<tuple<int, int, int>> g[N];

int L, R;
bool vis[N];

bool dfs(int u) {
  vis[u] = 1;
  if (u == n - 1) {
    return true;
  }
  for (auto &[v, l, r] : g[u]) {
    if (!vis[v] && l <= L && r >= R && dfs(v)) {
      return true;
    }
  }
  return false;
}

bool can(int l, int r) {
  memset(vis, 0, sizeof vis);
  L = l, R = r;
  return dfs(0);  
}

bool l_active[MAX];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m;
  FOR (i, 0, m) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    u--, v--;
    l_active[l] = 1;
    g[u].pb({v, l, r});
    g[v].pb({u, l, r});
  }

  int ans = 0;
  FOR (x, 1, MAX) {
    if (!l_active[x]) {
      continue;
    }
    int l = x, r = MAX;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (can(x, m)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    if (can(x, r)) {
      ans = max(ans, r - x + 1);
    }
  }

  if (!ans) {
    cout << "Oh, vamos!" << ENDL;
    return 0;
  }
  cout << ans << ENDL;

  return 0;
}