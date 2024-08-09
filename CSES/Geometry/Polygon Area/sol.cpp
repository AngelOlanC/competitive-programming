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

struct Point {
  int x, y;
  ll cross(Point p) { return 1ll * x * p.y - 1ll * p.x * y; }
};

ll areaPolygon(vector<Point>& p) {
  ll area = 0;
  FOR (i, 0, SZ(p)) area += p[i].cross(p[(i + 1) % SZ(p)]);
  return area;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<Point> p(n);
  for (auto &[x, y] : p) cin >> x >> y;

  cout << abs(areaPolygon(p)) << ENDL;

  return 0;
}
