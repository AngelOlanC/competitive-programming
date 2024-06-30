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

void solve(int t) {
  ll x, y, k;
  cin >> x >> y >> k;

  if (x % y == 0) {
    x++, k--;
  }

  ll last_x = -1;
  while (1) {
    ll d = y - (x % y);
    if (k <= d) {
      x += k;
      if (x % y == 0) {
        while (x % y == 0) {
          x /= y;
        }
        cout << x << ENDL;
        return;
      }
      cout << x << ENDL;
      return;
    }
    x += d;
    k -= d;
    while (x % y == 0) {
      x /= y;
    }
    if (x == last_x) {
      k %= d;
      continue;
    }
    last_x = x;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  FOR (i, 0, t) {
    solve(t + 1);  
  }

  return 0;
}