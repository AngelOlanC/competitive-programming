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

constexpr int maxn = 200000 + 5;

int deg[maxn];
int g[maxn];
int c[maxn];
ll v[maxn];
int vis[maxn];
vector<pi> gr[maxn];

void dfs_cycle(int u) {
  c[u] = 1;
  for (auto &[v, w] : gr[u]) {
    if (!c[v]) {
      dfs_cycle(v);
    }
  }
}

void dfs_value(int u, ll s = 0) {
  v[u] = s;
  for (auto &[v, w] : gr[u]) {
    dfs_value(v, s + w);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  g[n] = -1;
  vi a(n);
  FOR (i, 1, n) {
    cin >> a[i];
  }

  FOR (i, 1, n) {
    int j = i + a[i];
    if (j >= n) {
      g[i] = n;
      gr[n].pb({i, a[i]});
      continue;
    }
    int w = a[i] + a[j];
    j = j - a[j];
    if (j < 0) {
      g[i] = n;
    }
    else if (j == 0) {
      g[i] = i;
    }
    else {
      g[i] = j;
    }
    deg[g[i]]++;
    gr[g[i]].pb({i, w});
  }

  // FOR (i, 0, n) {
  //   cout << g[i] << ' ';
  // }
  // cout << ENDL;

  queue<int> q;
  FOR (u, 1, n) {
    if (!deg[u]) {
      q.push(u);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == n) {
      continue;
    }
    int v = g[u];
    deg[v]--;
    if (!deg[v]) {
      q.push(v);
    }
  }

  FOR (u, 1, n) {
    if (deg[u] && !c[u]){ 
      dfs_cycle(u);
    }
  }

  dfs_value(n);

  FOR (i, 1, n) {
    int j = i - a[i];
    if (j < 0) {
      cout << i + a[i] << ENDL;
      continue;
    }
    if (j == 0 || c[j]) {
      cout << -1 << ENDL;
      continue;
    }
    cout << v[j] + i + a[i] << ENDL;
  }
  cout << ENDL;

  // FOR (u, 0, n + 1) cout << c[u] << ' ';
  // cout << ENDL;

  return 0;
}