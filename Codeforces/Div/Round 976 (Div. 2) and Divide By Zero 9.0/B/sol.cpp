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
  ll k;
  cin >> k;
  auto get_sq = [&](ll x) -> ll {
    ll l = 0, r = 1e9;
    while (l < r) {
      ll m = (l + r + 1) / 2;
      if (m * m <= x) l = m;
      else r = m - 1;
    }
    return l;
  };
  auto can = [&](ll x) -> bool {
    return x - get_sq(x) >= k;
  };
  ll l = 1, r = 2e18;
  while (l < r) {
    ll m = (l + r) / 2;
    if (can(m)) r = m;
    else l = m + 1;
  }
  cout << l << ENDL;
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