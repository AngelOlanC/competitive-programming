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
  cin >> n;
  vector<ll> a(n);
  FOR (i, 0, n) cin >> a[i];

  ll l = 0, r = 1e12;
  while (l < r) {
    ll m = (l + r + 1) / 2;
    ll need = 0;
    ROF (i, n, 0) {
      if (a[i] < m) {
        need += m - a[i];
        continue;
      }
      ll give = min(a[i] - m, need);
      need = max(0ll, need - give);
    }
    if (!need) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  ll mn = l;
  l = 0, r = 1e12;
  while (l < r) {
    ll m = (l + r) / 2;
    bool ok = 1;
    ll spare = 0;
    ROF (i, n, 0) {
      if (a[i] <= m) {
        spare += m - a[i];
        continue;
      }
      if (spare < a[i] - m) {
        ok = 0;
        break;
      }
      spare -= a[i] - m;
    }
    if (ok) r = m;
    else l = m + 1;
  }
  ll mx = l;
  cout << mx - mn << ENDL;
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