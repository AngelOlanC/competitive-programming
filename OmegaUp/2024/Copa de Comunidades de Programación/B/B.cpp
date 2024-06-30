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

constexpr int N = 55, NG = N * N, INF = 1e5;

constexpr int di[4] = {0, -1, 0, 1}, dj[4] = {-1, 0, 1, 0};

int n, m, si, sj;
int a[N][N];
int d[NG];
vi g[NG];

int valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int encode(int i, int j) {
  return i * m + j;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m >> si >> sj;
  si--, sj--;

  if (n == 0 || m == 0) {
    cout << 0 << ENDL;
  }

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> a[i][j];
    }
  }

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      int u = encode(i, j);
      FOR (k, 0, 4) {
        int ii = i + di[k], jj = j + dj[k];
       
        if (valid(ii, jj)) {
          int v = encode(ii, jj);
          bool wall = (a[i][j] >> k) & 1;
          if (!wall) {
            g[u].pb(v);
          }
        }
      }
    }
  }

  fill(d, d + NG, INF);
  int x = encode(si, sj);
  d[x] = 0;
  queue<int> q;
  q.push(x);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v : g[u]) {
      if (d[u] + 1 < d[v]) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }

  int ans = INF;
  FOR (i, 0, m) {
    int up = a[0][i] & 2, down = a[n - 1][i] & 8;
    if (!up) {
      ans = min(ans, d[encode(0, i)]);
    }
    if (!down) {
      ans = min(ans, d[encode(n - 1, i)]);
    }
  }

  FOR (i, 0, n) {
    int left = a[i][0] & 1, right = a[i][m - 1] & 4;
    if (!left) {
      ans = min(ans, d[encode(i, 0)]);
    }
    if (!right) {
      ans = min(ans, d[encode(i, m - 1)]);
    }
  }
  
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << ENDL;

  return 0;
}