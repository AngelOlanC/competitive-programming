#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int maxn = 5000 + 5;

int n;
vi g[maxn];
ll c_sum[maxn];
ll val[maxn];
ll lazy[maxn];

void dfs_c_sum(int u) {
  if (g[u].empty()) {
    c_sum[u] = 1e12;
    return;
  }

  c_sum[u] = 0;
  for (auto &v : g[u]) {
    c_sum[u] += val[v];
    dfs_c_sum(v);
  }
}

void dfs_lazy(int u) {
  for (auto &v : g[u]) {
    dfs_lazy(v);
    lazy[u] += lazy[v];
    lazy[v] = 0;
  }
  val[u] += lazy[u];
}

ll balance(int r) {
  // cout << "processing " << r + 1 << ENDL;
  if (val[r] <= c_sum[r]) {
    return 0;
  }

  vector<pi> bfs_order;
  bfs_order.pb({r, 0});
  FOR (i, 0, SZ(bfs_order)) {
    auto [u, d] = bfs_order[i];
    for (auto &v : g[u]) {
      bfs_order.pb({v, d + 1});
    }
  }

  ll ans = 0, target = val[r] - c_sum[r];
  for (auto &[u, d] : bfs_order) if (u != r) {
    ll agg = min(c_sum[u] - val[u], target);
    lazy[u] = agg;
    target -= agg;
    ans += agg * d; 
    if (!target) {
      break;
    }
  }

  dfs_lazy(r);
  val[r] -= lazy[r];
  lazy[r] = 0;

  dfs_c_sum(r);

  // FOR (i, 0, n) {
  //   cout << val[i] << ' ';
  // }
  // cout << ENDL;
  // cout << "se agrega " << ans << ENDL;

  return ans;
}

void solve(int test_case) {
  cin >> n;

  FOR (i, 0, n) {
    cin >> val[i];
    g[i].clear();
  }
  FOR (i, 1, n) {
    int p;
    cin >> p;
    g[p - 1].pb(i);
  }

  dfs_c_sum(0);

  // FOR (i, 0, n) {
  //   cout << bfs_order[i] << ' ';
  // }
  // cout << END
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  L;

  ll ans = 0;
  ROF (i, n, 0) {
    ans += balance(i);
  }
  cout << ans  << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}