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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;
  vi a(n);
  for (auto &ai : a) {
    cin >> ai;
  }
  ll ans = 0, MX_MSK = 1 << n;
  for (int msk = 1; msk < MX_MSK; msk++) {
    int l = 1;
    FOR (i, 0, n) if ((msk >> i) & 1) {
      if (1ll * l * a[i] > 1ll * x * gcd(l, a[i])) {
        l = x + 1;
        break;
      }
      l = lcm(l, a[i]);
    }
    if (l <= x) {
      int add = x / l;
      ans += __builtin_popcount(msk) % 2 ? add : -add;
    }
  }
  cout << ans << ENDL;

  return 0;
}