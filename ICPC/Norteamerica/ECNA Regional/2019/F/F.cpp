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

using T = double;
using C = array<T, 4>;
using VC = vector<C>;

const T PI = acos(-1.0);
const T EPS = 1e-9;

bool intersect(C a, C b) {
  T dx = a[0] - b[0], dy = a[1] - b[1];
  T sr = a[2] + b[2];
  return dx * dx + dy * dy <= sr * sr;
}

set<int> intersected(VC circles) {
  set<int> inter;
  FOR (i, 0, SZ(circles)) {
    FOR (j, i + 1, SZ(circles)) {
      if (intersect(circles[i], circles[j])) {
        inter.insert(i);
        inter.insert(j);
      }
    }
  }
  return inter;
}

T area(C circle) {
  return PI * circle[2] * circle[2];
}

T radius(VC circles) {
  T sum_areas = 0;
  for (C &c : circles) {
    sum_areas += area(c);
  }
  return sqrtl(sum_areas / PI);
}

VC reduce(VC circles) {
  set<int> inter_i = intersected(circles);
  
  if (inter_i.empty()) {
    return VC();
  }

  VC inter, reduced;
  FOR (i, 0, SZ(circles)) {
    if (!inter_i.count(i)) {
      reduced.pb(circles[i]);
    } else {
      inter.pb(circles[i]);
    }
  }
  
  T x = 0, y = 0, r = radius(inter), s = 0;
  for (auto &[xx, yy, rr, ss] : inter) {
    x += xx;
    y += yy;
    s = max(s, ss);
  }
  x /= SZ(inter);
  y /= SZ(inter);
  reduced.pb({x, y, r, s});

  return reduced;
}

VC grow_circles(VC circles, T inc) {
  for (auto &[x, y, r, s] : circles) {
    r += s * inc;
  }
  return circles;
}

void print(C c) {
  FOR (i, 0, 4) {
    cout << c[i] << ' ';
  }
  cout << ENDL;
}

void print(VC circles) {
  for (C c : circles) {
    print(c);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  VC circles;

  FOR (i, 0, n) {
    int x, y, r, s;
    cin >> x >> y >> r >> s;
    circles.pb({x, y, r, s});
  }

  // print(circles);
  // print(grow_circles(circles, 1));

  cout << setprecision(9) << fixed;

  while (SZ(circles) > 1) {
    T min_pt = 1e18;
    FOR (i, 0, SZ(circles)) {
      FOR (j, i + 1, SZ(circles)) {
        auto [x0, y0, r0, s0] = circles[i];
        auto [x1, y1, r1, s1] = circles[j];
        T up = hypot(x0 - x1, y0 - y1) - r0 - r1;
        T down = s0 + s1;
        if (down == 0) {
          continue;
        }
        T pt = max(0.0, up / down);
        min_pt = min(min_pt, pt);
      }
    }
    circles = reduce(grow_circles(circles, min_pt));
  }

  C circle = circles[0];
  cout << circle[0] << ' ' << circle[1] << ENDL << circle[2] << ENDL;

  return 0;
}