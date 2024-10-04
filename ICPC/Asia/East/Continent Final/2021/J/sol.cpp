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

constexpr int INF = 1e9 + 5;

void solve_less_eq(int A, int B, vector<vi>& g, vi& a) {
  int N = SZ(g);
  vi d(N, -1);
  d[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : g[u]) if (d[v] == -1 && (ll)A * d[u] + a[0] > (ll)B * d[u] + a[v]) {
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  cout << d[N - 1] << ENDL;
}
void solve_greater(int D, vector<vi>& g, vi& a) {
  int N = SZ(g);
  int mx_time = -1;
  vi vis(N);
  vis[0] = 1;
  priority_queue<pi> pq;
  pq.push({1, 0});
  while (!pq.empty() && -pq.top().first <= mx_time) {
    int u = pq.top().second;
    pq.pop();
    for (auto &v : g[u]) if (!vis[v]) {
      vis[v] = 1;
      int dv = a[v] < a[0] ? 0 : ((a[v] - a[0]) / D + 1);
      pq.push({-dv, v});
    }
    ++mx_time;
  }
  while (!pq.empty()) pq.pop();
  vi d(N, INF);
  d[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    du = -du;
    pq.pop();
    if (du > d[u]) continue;
    for (auto &v : g[u]) {
      int y = a[v] < a[0] ? 0 : ((a[v] - a[0]) / D + 1);
      int dx = max(du, y);
      if (dx <= mx_time && dx + 1 < d[v]) {
        d[v] = dx + 1; 
        pq.push({-d[v], v});
      }
    }
  }
  if (d[N - 1] == INF) d[N - 1] = -1;
  cout << d[N - 1] << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<vi> g(N);
    while (M--) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].pb(v), g[v].pb(u);
    }
    vi a(N);
    FOR (i, 0, N) {
      cin >> a[i];
      if (i) a[i] += B;
    }
    if (A <= B) solve_less_eq(A, B, g, a);
    else solve_greater(A - B, g, a);
  }

  return 0;
} 