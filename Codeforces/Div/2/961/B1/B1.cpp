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

void solve(int test_case) {
  int n;
  ll m;
  cin >> n >> m;
  map<ll, ll> c;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    c[x]++;
  }

  ll ans = 0;
  for (auto &[x, k] : c) {
    ll t = min(k, m / x);
    ll curr = 1ll * x * t;
    if (c.count(x + 1)) {
      ll k2 = c[x + 1], t2 = min(k2, (m - curr) / (x + 1));
      curr += 1ll * (x + 1) * t2;
      curr = min(m, curr + min(k2 - t2, t));
    }
    ans = max(ans, curr);
  }
  cout << ans << ENDL;
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