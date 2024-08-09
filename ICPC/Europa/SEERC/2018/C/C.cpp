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

constexpr int maxn = 100 + 5;

int c[maxn];
int g[maxn][maxn];
pi e[maxn];
int cnt[maxn];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  FOR (i, 0, n) {
    cin >> c[i];
  }

  FOR (i, 0, n) {
    FOR (j, 0, n) {
      g[i][j] = 1e9;
    }
    g[i][i] = 0;
  }

  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e[i] = {u, v};
    g[u][v] = 1;
    g[v][u] = 1; 
  }

  FOR (k, 0, n) {
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  int ans = 1e9;
  FOR (i, 0, n) {
    memset(cnt, 0, sizeof cnt);
    FOR (j, 0, n) {
      if (c[j]) {
        cnt[g[i][j]]++;
      }
    }
    int seen = 0;
    FOR (j, 0, n) {
      seen += cnt[j];
      if (seen >= m) {
        ans = min(ans, j * 2);
        break;
      }
    }
  }

  FOR (i, 0, n - 1) {
    memset(cnt, 0, sizeof cnt);
    FOR (j, 0, n) {
      if (c[j]) {
        int md = min(g[j][e[i].first], g[j][e[i].second]);
        cnt[md]++;
      }
    }
    int seen = 0;
    FOR (j, 0, n) {
      seen += cnt[j];
      if (seen >= m) {
        ans = min(ans, j * 2 + 1);
        break;
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}