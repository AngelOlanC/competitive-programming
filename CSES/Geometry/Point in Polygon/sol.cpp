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
  ll cross(Point p) const { return 1ll + x * p.y - 1ll * y * p.x; }
  ll cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};

bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= 0; }

bool onSegment(Point a, Point b, Point p) {
  return a.cross(b, p) == 0 && inDisk(a, b, p);
}

int inPolygon(vector<Point>& poly, Point& p) {
  int n = SZ(poly), ans = 0;
  FOR(i, 0, n) {
    Point p1 = poly[i], p2 = poly[(i + 1) % n];
    if (p1.y > p2.y) swap(p1, p2);
    if (onSegment(p1, p2, p)) return 0;
    ans ^= (p1.y <= p.y && p.y < p2.y && p.cross(p1, p2) > 0);
  }
  return ans ? -1 : 1;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vector<Point> poly(n);
  for (auto &[x, y] : poly) cin >> x >> y;
  while (q--) {
    Point p;
    cin >> p.x >> p.y;
    int v = inPolygon(poly, p);
    cout << p.x<< ' ' << p.y << ' ' << (v == 1 ? "INSIDE" : (v == 0 ? "BOUNDARY" : "OUTSIDE")) << ENDL;
  }

  return 0;
}