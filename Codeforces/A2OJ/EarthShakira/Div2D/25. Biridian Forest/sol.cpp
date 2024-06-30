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

constexpr int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

constexpr int maxn = 1000 + 5;

char a[maxn][maxn];
int d[maxn][maxn];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  pi s, e;
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        s = {i, j};
      }
      if (a[i][j] == 'E') {
        e = {i, j};
      }
      d[i][j] = 1e9;
    }
  }

  queue<pi> q;
  q.push(e);
  d[e.first][e.second] = 0;
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    FOR (k, 0, 4) {
      int ii = i + di[k], jj = j + dj[k];
      if (ii >= 0 && ii < n && jj >= 0 && jj < m && a[ii][jj] != 'T' && d[i][j] + 1 < d[ii][jj]) {
        d[ii][jj] = d[i][j] + 1;
        q.push({ii, jj});
      }
    }
  }

  int ans = 0;
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      if (a[i][j] >= '0' && a[i][j] <= '9' && d[i][j] <= d[s.first][s.second]) {
        ans += a[i][j] - '0';
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}