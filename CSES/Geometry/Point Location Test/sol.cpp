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

using T = ll;
struct Point {
  T x, y;
  T cross(Point p) const { return x * p.y - y * p.x; }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    vector<Point> p(3);
    for (auto &[x, y] : p) cin >> x >> y;
    p[1].x -= p[0].x, p[1].y -= p[0].y;
    p[2].x -= p[0].x, p[2].y -= p[0].y;
    T cr = p[1].cross(p[2]);
    if (cr == 0) {
      cout << "TOUCH" << ENDL;
      continue;
    }
    if (cr > 0) {
      cout << "LEFT" << ENDL;
      continue;
    }
    cout << "RIGHT" << ENDL;
  }
  return 0;
}