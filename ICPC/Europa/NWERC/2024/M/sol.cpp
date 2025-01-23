#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using i128 = __int128_t;
using ld = long double;
struct Point {
  int x, y;
  ld cross(Point p) const { return (ld)x * p.y - (ld)y * p.x; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
};
ld area(vector<Point>& p) {
  ld area = 0.0;
  int n = p.size();
  for (int i = 0; i < n; ++i) {
    area += p[i].cross(p[(i + 1) % n]);
  }
  return abs(area) / 2.0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << setprecision(9) << fixed;
  int n;
  cin >> n;
  vector<Point> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  i128 sxi = p[0].x, syi = p[0].y, sxk = 0, syk = 0;
  for (int i = n - 1; i >= 2; --i) {
    sxk += p[i].x;
    syk += p[i].y;
  }
  i128 sum = 0;
  for (int j = 1; j < n - 1; ++j) {
    i128 A = (i128)j * p[j].x - sxi;
    i128 B = (i128)syk - (i128)(n - j - 1) * p[j].y;
    i128 C = (i128)j * p[j].y - syi;
    i128 D = (i128)sxk - (i128)(n - j - 1) * p[j].x;
    sum += A * B - C * D;
    
    sxi += p[j].x;
    syi += p[j].y;
    sxk -= p[j + 1].x;
    syk -= p[j + 1].y;
  }
  cout << (ld)sum / 2 / area(p) << '\n';

  return 0;
}