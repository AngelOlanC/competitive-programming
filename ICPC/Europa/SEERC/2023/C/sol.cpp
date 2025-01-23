#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr double EPS = 1e-9;

struct Point {
  double x, y;
  
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }

  Point operator*(double d) const { return {x * d, y * d}; }
  Point operator/(double d) const { return {x / d, y / d}; }

  bool operator<(Point p) const { return x < p.x - EPS || (abs(x - p.x) <= EPS && y < p.y - EPS); }
  bool operator==(Point p) const { return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS; }

  double sq() { return x * x + y * y; }
  double cross(Point p) const { return x * p.y - y * p.x; }
  double cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
  Point perp() { return {-y, x}; }
};

double dist(Point a, Point b) {
  return hypot(a.x - b.x, a.y - b.y);
} 

struct Circle {
  Point c;
  double r;
  bool contains(Point p) const {
    return (p - c).sq() <= r * r;
  }
};

Circle midPointCircle(Point p1, Point p2) {
  Point midPoint = (p1 + p2) / 2;
  return {midPoint, dist(p1, midPoint)};
}

Circle circleEnclosingPoints(vector<Point>& r) {
  if (r.empty()) {
    return {{0, 0}, 0};
  }
  if ((int)r.size() == 1) {
    return {r[0], 0};
  }
  if ((int)r.size() == 2) {
    return midPointCircle(r[0], r[1]);
  }
  Point a = r[0], b = r[1], c = r[2];
  b = b - a, c = c - a;
  if (b.cross(c) == 0) {
    sort(r.begin(), r.end());
    return midPointCircle(r[0], r[2]);
  }
  Point center = a + (b * c.sq() - c * b.sq()).perp() / b.cross(c) / 2;
  return {center, dist(center, r[0])};
}

Circle welz(int i, vector<Point>& p, vector<Point>& r) {
  if (i == (int)p.size() || r.size() == 3) {
    return circleEnclosingPoints(r);
  }
  Circle c = welz(i + 1, p, r);
  if (c.contains(p[i])) {
    return c;
  }
  r.push_back(p[i]);
  c = welz(i + 1, p, r);
  r.pop_back();
  return c;
}

vector<Point> convexHull(vector<Point> pts) {
  if ((int)pts.size() <= 1) return pts;
  sort(pts.begin(), pts.end());
  vector<Point> h((int)pts.size() + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end()))
    for (Point p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) {
        t--;
      }
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

void reorder_polygon(vector<Point>& pts) {
  int mn = 0;
  for (int i = 1; i < (int)pts.size(); ++i) {
    if (pts[i].y < pts[mn].y || (pts[i].y == pts[mn].y && pts[i].x < pts[mn].y)) {
      mn = i;
    }
  }
  rotate(pts.begin(), pts.begin() + mn, pts.end());
}

vector<Point> minkowski(vector<Point> P, vector<Point> Q) {
  reorder_polygon(P);
  reorder_polygon(Q);

  P.push_back(P[0]);
  P.push_back(P[1]);
  Q.push_back(Q[0]);
  Q.push_back(Q[1]);

  vector<Point> result;
  int i = 0, j = 0;
  while(i < P.size() - 2 || j < Q.size() - 2){
    result.push_back(P[i] + Q[j]);
    auto cross = (P[i + 1] - P[i]).cross(Q[j + 1] - Q[j]);
    if(cross >= 0 && i < P.size() - 2) {
      ++i;
    }
    if(cross <= 0 && j < Q.size() - 2) {
      ++j;
    }
  }
  return result;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Point> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
    x = -x;
    y = -y;
  }

  int m;
  cin >> m;
  vector<Point> b(m);
  for (auto &[x, y] : b) {
    cin >> x >> y;
  }

  vector<Point> qp = minkowski(convexHull(a), convexHull(b));

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  shuffle(qp.begin(), qp.end(), rng);

  vector<Point> r;
  Circle cc = welz(0, qp, r);

  cout << setprecision(12) << fixed;
  cout << cc.r << ' ' << cc.c.x << ' ' << cc.c.y << '\n';

  return 0;
}