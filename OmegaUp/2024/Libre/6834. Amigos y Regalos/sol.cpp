#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll c1, c2, x1, x2;
  cin >> c1 >> c2 >> x1 >> x2;

  ll l = 1, r = 1e12;
  while (l < r) {
    ll m = (l + r) / 2;
    ll mx1 = m / x1, mx2 = m / x2;
    ll to_assign = c1 - min(c1, mx2) + c2 - min(c2, mx1);
    ll alive = m - mx1 - mx2 + m / (x1 * x2);
    if (alive >= to_assign) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << ENDL;

  return 0;
}