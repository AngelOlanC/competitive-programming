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

constexpr int maxn = 1e5 + 5;

int n, k;
vi g[maxn];
int mx[maxn];
priority_queue<int> pq;

void dfs(int u) {
  if (mx[u] == 0) return;
  for (auto &v : g[u]) if (mx[u] - 1 > mx[v]) {
    if (mx[v] == -1) pq.push(-v);
    mx[v] = mx[u] - 1;
    dfs(v);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> k;
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[--u].pb(--v), g[v].pb(u);
  }
  memset(mx, -1, sizeof mx);
  pq.push(0);
  while (!pq.empty()) {
    int u = -pq.top();
    pq.pop();
    cout << u + 1 << ' ';
    mx[u] = k;
    dfs(u);
  }
  cout << ENDL;

  return 0;
}