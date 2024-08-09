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

const int maxn = 100 + 5, maxrs = 50 + 5, maxcap = 2000000 + 5;

int r, s, n;
int sr, ss;
int a[maxrs];
int b[maxrs];
int c[maxn];
int can[maxcap];
int dp[maxn][maxrs][maxrs];

int solve(int i, int j, int k) {
  if (i == n) {
    return 1;
  }
  if (dp[i][j][k]) {
    return 0;
  }
  dp[i][j][k] = 1;
  int jj = j, pj = 0;
  FOR (dj, 0, r) {
    int kk = k, pk = 0;
    FOR (dk, 0, s) {
      int left = c[i] - pj - pk;
      
      if (left < 0) {
        break;
      }
      
      if (can[left] && solve(i + 1, jj, kk)) {
        return true;
      }
      pk += b[kk];
      kk = (kk + 1) % s;
    }
    pj += a[jj];
    jj = (jj + 1) % r;
  }
  return 0;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> r >> s >> n;
  FOR (i, 0, r) {
    cin >> a[i];
    sr += a[i];
  }
  FOR (i, 0, s) {
    cin >> b[i];
    ss += b[i];
  }
  FOR (i, 0, n) {
    cin >> c[i];
  }

  can[0] = 1;
  FOR (i, 1, maxcap) {
    if (i - sr >= 0) {
      can[i] |= can[i - sr];
    }
    if (i - ss >= 0) {
      can[i] |= can[i - ss];
    }
  }

  cout << (solve(0, 0, 0) ? "yes" : "no") << ENDL;

  return 0;
}