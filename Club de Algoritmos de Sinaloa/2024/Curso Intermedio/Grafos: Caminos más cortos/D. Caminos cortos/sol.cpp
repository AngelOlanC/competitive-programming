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

#define N 100005
#define K 4

constexpr int INF = 1 << 28;

int n, m;
vector<pi> g[N][2];

vi bfs(int s, int gn) {
  vi d(n, INF);
  d[s] = 0;

  queue<int> q[K];
  q[0].push(s);

  int in_q = 1, i = 0;
  while (in_q) {
    while (q[i].empty()) {
      i = (i + 1) % K;
    } 
    int u = q[i].front();
    q[i].pop();
    in_q--;
    for (auto &[v, w] : g[u][gn]) {
      if (d[u] + w < d[v]) {
        d[v] = d[u] + w;
        q[(i + w) % K].push(v);
        in_q++;
      }
    }
  }
  return d;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u][0].pb({v, w});
    g[v][1].pb({u, w});
  }

  vi ds = bfs(0, 0);
  vi de = bfs(n - 1, 1);

  FOR (i, 0, n) {
    int x = ds[i] + de[i];
    if (x >= INF) {
      x = -1;
    }
    cout << x << ' ';
  }
  cout << ENDL;

  return 0;
}