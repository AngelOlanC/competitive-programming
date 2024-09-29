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

constexpr int INF = 1e7;

using ld = double;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;
  
  vector<vi> G(n);
  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].pb(v), G[v].pb(u);
  }

  vector<vi> D(n, vi(n, -1));
  FOR (i, 0, n) {
    D[i][i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &v : G[u]) if (D[i][v] == -1) {
        D[i][v] = D[i][u] + 1;
        q.push(v);
      }
    }
  }

  int s1, t1, s2, t2;
  cin >> s1 >> t1 >> s2 >> t2;
  --s1, --t1, --s2, --t2;
  
  vi mn_diff(n + 1, INF);
  mn_diff[0] = D[s1][t1] + D[s2][t2];
  FOR (u, 0, n) FOR (v, 0, n) if (D[s1][u] != -1 && D[s2][u] != -1 && D[u][v] != -1) {
    int mn = D[s1][u] + D[v][t1] + D[s2][u] + D[v][t2];
    mn = min(mn, D[s1][u] + D[v][t1] + D[s2][v] + D[u][t2]);
    mn = min(mn, D[s1][v] + D[u][t1] + D[s2][u] + D[v][t2]);
    mn = min(mn, D[s1][v] + D[u][t1] + D[s2][v] + D[u][t2]);
    mn_diff[D[u][v]] = min(mn_diff[D[u][v]], mn);
  }

  auto f = [](int d, int k) -> ld {
    if (d == 0) return 0;
    return 1.0/(k/d+1)*(d-(k%d))+1.0/(k/d+2)*(k%d);
  };

  auto check = [&](int mid, int i) -> ld {
    return f(mn_diff[i], k - mid) + f(i, mid)*2;
  };

  ld ans = 1e14;
  FOR (i, 0, n + 1) if (mn_diff[i]  != INF) {
    int l = 0, r = k;
    while (l <= r) {
      int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
      if (check(m1, i) < check(m2, i)) {
        r = m2 - 1;
      } else {
        l = m1 + 1;
      } 
    }
    ans = min(ans, check(r, i));
  }
  cout << fixed << setprecision(13) << ans << ENDL;

  return 0;
}