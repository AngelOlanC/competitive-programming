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

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  // (para doubles, usar inf = 1/.0, div(a,b) = a/b)
  static const ll inf = LLONG_MAX;
  ll div(ll a, ll b) {  // floored division
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    if (empty()) return -1e18;
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  ll s = 0;
  vector<ll> a(n), p(n + 3);
  FOR (i, 0, n) {
    cin >> a[i];
    p[i + 1] = p[i] + a[i];
    s += a[i] * (i + 1);
  }

  ll ans = s;
  LineContainer lcl, lcr;
  FOR (i, 0, n) { 
    ll val = s - a[i] * (i + 1) + p[i] + lcl.query(a[i]);
    ans = max(ans, val);
    lcl.add(i + 1, -p[i]);
  }
  // cout << s << ENDL;
  ROF (i, n, 0) {
    ll val = s - a[i] * (i + 1) - (p[n] - p[i + 1]) + lcr.query(a[i]);
    // cout << i << ' ' << a[i] << ' ' << p[n] - p[i + 1] << ' ' << lcr.query(a[i]) << ' ' << val << ENDL;
    ans = max(ans, val);
    lcr.add(i + 1, p[n] - p[i + 1]);
  }
  cout << ans << ENDL;

  return 0;
}