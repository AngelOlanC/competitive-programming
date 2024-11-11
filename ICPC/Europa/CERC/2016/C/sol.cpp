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

const double PI = acos(-1.0);
inline double RAD_to_DEG(double r) { return (r * 180.0 / PI); }

using T = double;
struct Point {
  T x, y;
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  T dot(Point p) { return x * p.x + y * p.y; }
};

double angle(Point v, Point w) { return acos(clamp(v.dot(w) / v.norm() / w.norm(), -1.0, 1.0)); }
double angle(Point o, Point a, Point b) { return angle(a - o, b - o); }
double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  double HT = sqrt(0.75), DHT = 1.0 - HT;

  int n;
  string s;
  cin >> n >> s;

  bool only_t = 1;
  FOR (i, 0, n) {
    if (s[i] != 'T') {
      only_t = 0;
      break;
    }
  }
  
  if (only_t) {
    cout << 2 * n + 1 << ENDL;
    return 0;
  }

  double ans = 2 * n + 2;

  auto f = [&]() -> void {
    if (s[0] == 'S') {
      return;
    }
    if (s[0] == 'C') {
      ans -= 2;
      ans += PI / 2;
      return;
    }
    --ans;
    int i = 1;
    while (s[i] == 'T') {
      ++i;
      --ans;
    }
    if (s[i] == 'S') {
      ans += hypot(DHT, i - 0.5);
      return;
    }
    double dist_to_origin = hypot(HT - 0.5, i), th = acos(0.5 / dist_to_origin);
    double d = atan2(HT - 0.5, -i), d1 = d - th;
    ans -= 0.5;
    Point origin_circle = {i + 0.5, 0.5}, tangent = {i + 0.5 + 0.5 * cos(d1), 0.5 + 0.5 * sin(d1)}, top_circle = {i + 0.5, 1};
    ans += sin(th) * dist_to_origin + PI / 360.0 * RAD_to_DEG(angle(origin_circle, top_circle, tangent));
  };

  f();
  reverse(ALL(s));
  f();

  cout << setprecision(9) << fixed << ans << ENDL;

  return 0;
}