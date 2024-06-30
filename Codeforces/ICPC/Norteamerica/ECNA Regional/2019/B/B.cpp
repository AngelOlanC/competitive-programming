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

constexpr int N = 1005, G_N = N * 365;
constexpr int INF = 1e7;

int t[N][N], a[N][N];

vector<pi> g[2][G_N];
int d[2][G_N];

int encode(int u, int a) {
  return u * 360 + a;
}

int left_angle_diff(int a1, int a2) {
  int d = a2 - a1;
  return d >= 0 ? d : 360 - a1 + a2;
}

int right_angle_diff(int a1, int a2) {
  return left_angle_diff(a2, a1);
}

void dijkstra(int k) {
  priority_queue<pi> pq;
  fill(d[k], d[k] + G_N, INF);

  FOR (a, 0, 360) {
    int i = encode(0, a);
    d[k][i] = 0;
    pq.push({0, i});
  }

  while (!pq.empty()) {
    auto [w, u] = pq.top();
    w = -w;
    pq.pop();

    if (w > d[k][u]) {
      continue;
    }

    for (auto &[v, ww] : g[k][u]) {
      if (w + ww < d[k][v]) {
        d[k][v] = w + ww;
        pq.push({-d[k][v], v});
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, target, l, r;
  cin >> n >> target >> l >> r;
  target--;
  
  FOR (u, 0, n) {
    int m;
    cin >> m;
    while (m--) {
      int v;
      cin >> v;
      --v;
      cin >> t[u][v] >> a[u][v];
    }
  }

  if (!target) {
    cout << 0 << ENDL;
    return 0;
  }

  FOR (u, 0, n) {
    FOR (v, 0, n) {
      if (!t[u][v]) {
        continue;
      }

      int out_u = a[u][v];
      int in_v = (a[v][u] + 180) % 360;
      
      FOR (au, 0, 360) {
        int l_d = left_angle_diff(au, out_u), r_d = right_angle_diff(au, out_u);
        if (l_d > l && r_d > r) {
          continue;
        }
        int i = encode(u, au), j = encode(v, in_v);
        g[0][i].pb({j, t[u][v]});
        g[1][j].pb({i, t[u][v]});
      }
    }
  }

  dijkstra(0);
  dijkstra(1);
  
  int ans = INF;
  FOR (a, 0, 360) {
    int i = encode(target, a);
    ans = min(ans, d[0][i] + d[1][i]);
  }

  if (ans == INF) {
    cout << "impossible" << ENDL;
    return 0;
  }
  cout << ans << ENDL;

  return 0;
}