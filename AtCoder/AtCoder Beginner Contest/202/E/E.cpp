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

constexpr int maxn = 2e5 + 5;

int n;
int ans[maxn];
int timer = -1, in[maxn], out[maxn];
vi g[maxn];
vi at_depth[maxn];

void dfs(int u, int d = 0) {
  in[u] = ++timer;
  at_depth[d].pb(in[u]);
  for (auto &v : g[u]) {
    dfs(v, d + 1);
  }
  out[u] = timer;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  FOR (u, 1, n) {
    int p;
    cin >> p;
    g[p - 1].pb(u);
  }

  dfs(0);

  int q;
  cin >> q;
  FOR (i, 0, q) {
    int u, d;
    cin >> u >> d;
    --u;
    cout << upper_bound(ALL(at_depth[d]), out[u]) - lower_bound(ALL(at_depth[d]), in[u]) << ENDL;
  }

  return 0;
}