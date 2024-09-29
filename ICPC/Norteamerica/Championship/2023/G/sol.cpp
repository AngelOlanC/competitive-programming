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

using ld = double;

ld a[1005][1005], p;
int r, c;

ld A(int x, int y) {
  if (x < 0 || y < 0) return 1e18;
  return a[x][y];
}

ld f(ld x, ld y) {
  if (x < y) return x;  
  ld up = min(x - y, p);
  return (y + up/2.0)*(up/p)+x*(1.0-up/p);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int p2;
  cin >> r >> c >> p2;
  p = p2;
  FOR (i, 0, r) {
    FOR (j, 0, p) {
      if (i == 0 && j == 0) continue;
      a[i][j] = (f(A(i-1,j),A(i,j-1))+f(A(i,j-1),A(i-1,j)))/2.0;
    }
  }
  cout << setprecision(10) << fixed << a[r - 1][c - 1] << ENDL;

  return 0;
}
