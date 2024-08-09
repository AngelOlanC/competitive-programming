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

#define N 200010

int n;
int c[N];
int p[N];
int h[N];
int l[N];
int r[N];
vi g[N];

void build_tree(int u, int he, int par) {
  h[u] = he;
  p[u] = par;
  
  for (auto &v : g[u]) {
    if (v != par) {
      c[u]++;
      if (!l[u]) {
        l[u] = v;
      } else {
        r[u] = v;
      }
      build_tree(v, he + 1, u);
    }
  }
}

set<pi> leaves[N];

int balance(int u) {
  if (!u) {
    return 0;
  }
  if (!c[u]) {
    leaves[u].insert({-h[u], u});
    return 0;
  }

  int ans = balance(l[u]) + balance(r[u]);
  if (!r[u]) {
    swap(leaves[l[u]], leaves[u]);
    
    while (!leaves[u].empty() && -leaves[u].begin()->first - h[u] != 1) {
      auto [hv, v] = *leaves[u].begin();
      ans++;
      leaves[u].erase(leaves[u].begin());
      c[p[v]]--;
      if (!c[p[v]]) {
        leaves[u].insert({-h[p[v]], p[v]});
      }
    }
    
    return ans;
  }

  int max_h_l = -leaves[l[u]].begin()->first;
  int max_h_r = -leaves[r[u]].begin()->first;

  if (SZ(leaves[l[u]]) > SZ(leaves[r[u]])) {
    swap(leaves[l[u]], leaves[u]);
    for (auto it : leaves[r[u]]) {
      leaves[u].insert(it);
    }
  } else {
    swap(leaves[r[u]], leaves[u]);
    for (auto it : leaves[l[u]]) {
      leaves[u].insert(it);
    }
  }

  int min_h = min(max_h_l, max_h_r);

  while (!leaves[u].empty() && -leaves[u].begin()->first - min_h > 1) {
    auto [hv, v] = *leaves[u].begin();
    ans++;
    leaves[u].erase(leaves[u].begin());
    c[p[v]]--;
    if (!c[p[v]]) {
      leaves[u].insert({-h[p[v]], p[v]});
    }
  }

  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;

  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v), g[v].pb(u);
  }

  build_tree(1, 0, 0);

  cout << balance(1) << ENDL;

  return 0;
}