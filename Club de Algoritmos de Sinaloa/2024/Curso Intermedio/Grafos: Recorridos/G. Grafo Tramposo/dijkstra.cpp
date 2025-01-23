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

vector<tuple<int, int, int>> g[N];
bool l_active[MAX];
int d[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
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
  FOR (l, 1, MAX) {
    if (!l_active[l]) {
      continue;
    }
    memset(d, -1, sizeof d);
    d[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({MAX, 0});
    while (!pq.empty()) {
      auto [r, u] = pq.top();
      pq.pop();
      if (d[u] > r) {
        continue;
      }
      for (auto &[v, ll, rr] : g[u]) {
        int new_r = min(r, rr);
        if (ll <= l && d[v] < new_r) {
          d[v] = new_r;
          pq.push({d[v], v});
        }
      }
    }
    if (d[n - 1] >= l) {
      ans = max(ans, d[n - 1] - l + 1);
    }
  }

  if (!ans) {
    cout << "Oh, vamos!" << ENDL;
    return 0;
  }
  cout << ans << ENDL;

  return 0;
}