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

struct Angle {
	int x, y;
	int t = 0;
  int id;
	Angle operator-(Angle b) const { return {x-b.x, y-b.y, t}; }
	int half() const {
		assert(x || y);
		return y < 0 || (y == 0 && x < 0);
	}
  int dot(Angle b) const { return x * b.x + y * b.y; }
  int cross(Angle b) const { return x * b.y - y * b.x; }
	Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
	Angle t180() const { return {-x, -y, t + half()}; }
	Angle t360() const { return {x, y, t + 1, id}; }
};
bool operator<(Angle a, Angle b) {
	return make_tuple(a.t, a.half(), a.y * (ll)b.x) <
	       make_tuple(b.t, b.half(), a.x * (ll)b.y);
}
bool operator==(Angle a, Angle b) {
  return tie(a.x, a.y, a.t) == tie(b.x, b.y, b.t);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vi> app(1001, vi(1001));
  pair<Angle, int> c;
  cin >> c.first.x >> c.first.y;
  app[c.first.x][c.first.y]++;
  FOR (i, 0, n - 1) {
    int x, y;
    cin >> x >> y;
    app[x][y]++;
  }
  if (n == 1) {
    cout << "1 1\n";
    return 0;
  }
  int gid = 0;
  vector<pair<Angle, int>> p;
  FOR (x, 0, 1001) FOR (y, 0, 1001) if (app[x][y] && (x != c.first.x || y != c.first.y)) {
    Angle ang = {x, y, 0, gid++};
    p.pb({ang - c.first, app[x][y]});
  }
  c.second = app[c.first.x][c.first.y];
  int m = SZ(p);
  sort(ALL(p));
  int j = 0;
  while (j != m - 1 && !p[j].first.cross(p[j + 1].first) && p[j].first.dot(p[j + 1].first) > 0) ++j;
  j = (j + 1) % m;
  rotate(p.begin(), p.begin() + j, p.end());
  int cnt = p[0].second;
  vector<pair<Angle, int>> a;
  FOR (i, 0, m) {
    j = (i + 1) % m;
    if (i != m - 1 && !p[i].first.cross(p[j].first) && p[i].first.dot(p[j].first) > 0) {
      cnt += p[j].second;
      continue;
    }
    a.pb({p[i].first, cnt});
    cnt = p[j].second;
  }
  m = SZ(a);
  // for (auto &[p, cnt] : a) cout << p.x << ' ' << p.y << ' ' << cnt << ENDL;
  // cout << m << ENDL;
  FOR (i, 0, m) a.pb({a[i].first.t360(), a[i].second});
  sort(ALL(a));
  j = 0;
  int lo = n, hi = 1, l = 0;
  FOR (i, 0, m) {
    while (a[j].first < a[i].first.t180()) l += a[j++].second;
    l -= a[i].second;
    auto [x0, y0, t0, id0] = a[i].first;
    // auto [x1, y1, t1, id1] = a[j].first;
    if ((x0 > 0 && y0 > 0) || (x0 < 0 && y0 < 0)) continue;
    int s = a[i].second + c.second;
    if (a[i].first.id != a[j].first.id && !a[i].first.cross(a[j].first)) s += a[j].second;
    int g = n - s - l;
    int aux_l = l;
    if (a[i].first.x > 0 || (a[i].first.x == 0 && a[i].first.y < 0)) swap(g,aux_l);
    // cout << g << ' ' << l << ' ' << s << ENDL;
    lo = min(lo, g + 1);
    hi = max(hi, n - aux_l);
    // cout<<i<<' '<<j<<' '<<x0+c.first.x<<' '<<y0+c.first.y<<' '<<x1+c.first.x<<' '<<y1+c.first.y<<' '<<g<<' '<<l<<' '<<s<<ENDL;
  }
  int g = 0, s = c.second;  // probar con linea horizontal
  FOR (i, 0, m) {
    if (a[i].first.y > 0) g += a[i].second;
    if (a[i].first.y == 0) s += a[i].second;
  }
  l = n - g - s;
  lo = min(lo, g + 1);
  hi = max(hi, n - l);
  cout << lo << ' ' << hi << ENDL;
  return 0;
}