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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6;
  cin >> x >> y >> z >> x1 >> y1 >> z1 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

  int ans = 0;
  if (y < 0) {
    ans += a1;
  }
  if (y > y1) {
    ans += a2;
  }
  if (z < 0) {
    ans += a3;
  }
  if (z > z1) {
    ans += a4;
  }
  if (x < 0) {
    ans += a5;
  }
  if (x > x1) {
    ans += a6;
  }
  cout << ans << ENDL;

  return 0;
}