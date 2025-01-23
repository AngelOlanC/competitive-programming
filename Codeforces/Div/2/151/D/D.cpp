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

#define N 100010

int cnt[N];
int c[N];
int taken[N];
int appeared[N];
vi g[N], gc[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  FOR (i, 0, n) {
    cin >> c[i];
    c[i]--;
    appeared[c[i]] = 1;
    gc[c[i]].pb(i);
  } 
  
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  memset(taken, -1, sizeof taken);
  FOR (i, 0, N) {
    for (auto &u : gc[i]) {
      for (auto &v : g[u]) {
        if (c[u] != c[v] && taken[c[v]] != i) {
          taken[c[v]] = i;
          cnt[c[v]]++;
        }
      }
    }
  }

  int ans = -1;
  FOR (i, 0, N) {
    if (appeared[i] && (ans == -1 || cnt[i] > cnt[ans])) {
      ans = i;
    }
  }
  cout << ans + 1 << ENDL;

  return 0;
}