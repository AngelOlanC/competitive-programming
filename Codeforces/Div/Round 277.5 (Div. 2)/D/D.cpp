#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  
  vi g[n];
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u - 1].pb(v - 1);
  }

  int ans = 0;
  FOR (u, 0, n) {
    vi cnt(n, 0);
    for (auto &v : g[u]) {
      for (auto &w : g[v]) {
        cnt[w]++;
      }
    }
    FOR (v, 0, n) {
      if (v != u) {
        ans += cnt[v] * (cnt[v] - 1) / 2;
      }
    }
  }

  cout << ans << ENDL;

  return 0;
}