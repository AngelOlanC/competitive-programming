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

constexpr int maxx = 1e6 + 5, INF = 1e8;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vi a(n);
  FOR (i, 0, n) cin >> a[i];

  vi g(maxx, INF), l(maxx, -INF);
  FOR (i, 0, m) {
    int x;
    cin >> x;
    g[x] = l[x] = x;
  }
  ROF (i, maxx - 1, 0) if (g[i] == INF) g[i] = g[i + 1];
  FOR (i, 1, maxx) if (l[i] == -INF) l[i] = l[i - 1];

  int last = -1;
  bool zero = 0;
  FOR (i, 0, n) {
    if (!a[i]) {
      zero = 1;
      continue;
    }
    if (!zero) {
      last = a[i];
      continue;
    }
    zero = 0;
    if (last == -1) {
      vi cand;
      if (g[a[i]] != INF) cand.pb(g[a[i]]);
      if (l[a[i]] != -INF) cand.pb(l[a[i]]);
      int best = INF;
      for (auto &x : cand) if (abs(x - a[i]) < abs(best - a[i])) best = x;
      a[i - 1] = best;
      last = a[i];
      continue;
    }
    vi cand;
    if (g[a[i]] != INF) cand.pb(g[a[i]]);
    if (l[a[i]] != -INF) cand.pb(l[a[i]]);
    if (g[last] != INF) cand.pb(g[last]);
    if (l[last] != -INF) cand.pb(l[last]);
    int best = INF;
    for (auto &x : cand) if (abs(last - x) + abs(a[i] - x) < abs(last - best) + abs(a[i] - best)) best = x;
    a[i - 1] = best;
    last = a[i];
  }
  if (zero) {
    if (last == -1) {
      a[n - 1] = g[0];
    } else {
      vi cand;
      if (g[last] != INF) cand.pb(g[last]);
      if (l[last] != -INF) cand.pb(l[last]);
      int best = INF;
      for (auto &x : cand) if (abs(x - last) < abs(best - last)) best = x;
      a[n - 1] = best;
    }
  }

  ROF (i, n - 1, 0) if (!a[i]) a[i] = a[i + 1];

  ll s = 0;
  FOR (i, 1, n) s += abs(a[i] - a[i - 1]);

  cout << s << ENDL;
  FOR (i, 0, n) cout << a[i] << " \n"[i == n - 1];

  return 0;
}