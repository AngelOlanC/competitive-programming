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

struct HASH {
  size_t operator()(const pair<int, int>& x) const {
    return (size_t)x.first * 37U + (size_t)x.second;
  }
};

constexpr int sgn_x[4] = {1, -1, -1, 1}, sgn_y[4] = {-1, -1, 1, 1};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int ns, nt, rmax;
  cin >> ns >> nt >> rmax;

  vector<pi> p(ns);
  for (auto &[l, r] : p) {
    cin >> l >> r;
  }

  vector<pi> d(nt);
  for (auto &[df, ds] : d) {
    cin >> ds >> df;
  }

  pi INF_PAIR = {1e9, 1e9}, ans = INF_PAIR;
  FOR (dir, 0, 4) {
    // cout << dir << ENDL;
    map<pi, int> m;
    for (auto &[x, y] : p) {
      // cout << ' ' << x << ' ' << y << ENDL;
      for (auto &[df, ds] : d) {
        int xx = x + df * sgn_x[dir], yy = y + ds * sgn_y[dir];
        // cout << "  " << xx << ' ' << yy << ENDL;
        m[{xx, yy}]++;
      }
    }
  
    for (auto &[pt, cnt] : m) if (cnt == nt) {
      auto [x, y] = pt;
      int cnt = 0, good = 1;
      for (auto &[xx, yy] : p) {
        if (x == xx && y == yy) {
          good = 0;
          break;
        }
        cnt += abs(xx - x) + abs(yy - y) <= rmax;
      }
      if (good && cnt == nt) {
        if (ans != INF_PAIR) {
          cout << "Ambiguous" << ENDL;
          return 0;
        }
        ans = {x, y};
      }
    }

    for (auto &[df, ds] : d) {
      swap(df, ds);
    }
  }

  if (ans == INF_PAIR) {
    cout << "Impossible" << ENDL;
    return 0;
  }

  cout << ans.first << ' ' << ans.second << ENDL;

  return 0;
}