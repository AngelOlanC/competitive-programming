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
#define LOG 25

int n;
int m;
int h[N];
int jmp[N][LOG];
int mx[N][LOG];
vector<pi> g[N];

void build_tree(int u = 0, int p = -1) { 
  for (auto &[v, w] : g[u]) {
    if (v != p) {
      h[v] = h[u] + 1;
      build_tree(v, u);
      jmp[v][0] = u;
      mx[v][0] = w;
    }
  }
}

void build_dp() {
  for (int l = 1; l < LOG; l++) {
    for (int u = 0; u < n; u++) {
      jmp[u][l] = jmp[jmp[u][l - 1]][l - 1];
      mx[u][l] = max(mx[u][l - 1], mx[jmp[u][l - 1]][l - 1]); 
    }
  }
}

int p[N];
void calc_ans() {

}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  FOR (i, 1, n) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb({v, w}), g[v].pb({u, w});
  }

  build_tree();

  build_dp();

  return 0;
}