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
  
bool vis[44777445];
int n, i = 0, j = 1;
int qx[10000100];
int qp[10000100];
int ql[10000100];
int ans[110];

void process(int x, int l, int p) {
  if (vis[x] || x > n) {
    return;
  }
  vis[x] = 1;
  qx[j] = x;
  ql[j] = l;
  qp[j] = p;
  j++;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;

  qx[0] = 0;

  while (!vis[n]) {
    int x = qx[i];
    // cout << x << ' ' << ql[i] << ' ' << qp[i] << ENDL;

    int l = 1, r = 400;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (x + m * m * m <= n) {
        l = m;
      } else {
        r = m - 1;
      }
    }

    ROF (d, 100, 0) {
      if (l - d <= 0) {
        continue;
      }
      int k = l - d;
      process(x + k * k * k, i, k);
    }

    i++;
  }

  j--;
  int z = 0, cnt = 0;
  while (qx[j]) {
    ans[z++] = qp[j];
    j = ql[j];
  }

  cout << z << ENDL;
  FOR (i, 0, z) {
    cout << ans[i] << ' ';
  }
  cout << ENDL;

  return 0;
}