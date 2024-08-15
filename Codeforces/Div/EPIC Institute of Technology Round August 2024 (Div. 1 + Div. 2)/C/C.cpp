#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll dist(int x1, int y1, int x2, int y2) {
  ll dx = x1 - x2, dy = y1 - y2;
  return dx * dx + dy * dy;
}

void solve(int test_case) {
  int n;
  cin >> n;
  vi x(n), y(n);
  FOR (i, 0, n) cin >> x[i] >> y[i];
  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  ll d = dist(xs, ys, xt, yt);
  FOR (i, 0, n) if (dist(xt, yt, x[i], y[i]) <= d) {
    cout << "NO" << ENDL;
    return;
  }
  cout << "YES" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}