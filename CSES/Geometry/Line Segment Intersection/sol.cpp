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
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  ll dot(Point p) { return 1ll * x * p.x + 1ll * y * p.y; }
  ll cross(Point p) { return 1ll * x * p.y - 1ll * p.x * y; }
};

int orient(Point a, Point b, Point c) {
  ll cr = (b - a).cross(c - a);
  return cr < 0 ? -1 : min(cr, 1LL);
}

bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= 0; }

bool onSegment(Point a, Point b, Point p) {
  return (a - p).cross(b - p) == 0 && inDisk(a, b, p);
}

bool properInter(Point a, Point b, Point c, Point d) {
  int oa = orient(c, d, a),
         ob = orient(c, d, b),
         oc = orient(a, b, c),
         od = orient(a, b, d);
  return oa * ob < 0 && oc * od < 0;
}

bool segInter(Point a, Point b, Point c, Point d) {
  return properInter(a, b, c, d) || 
      onSegment(c, d, a) || onSegment(c, d, b) ||
      onSegment(a, b, c) || onSegment(a, b, d);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    vector<Point> p(4);
    for (auto &[x, y] : p) cin >> x >> y;
    cout << (segInter(p[0], p[1], p[2], p[3]) ? "YES" : "NO") << ENDL;
  }

  return 0;
}