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

ll s;

ll f(double r) {
  ll ans = 0, lim = (ll) r;
  FOR (i, 1, lim + 1) {
    ans += (ll)sqrt(r * r - i * i);
  }
  return ans * 4 > s;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> s;

  double l = 0, r = 1e7;
  FOR (i, 0, 200) {
    double m = (l + r) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << setprecision(10) << fixed << l << ENDL;

  return 0;
}