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
  ll n;
  cin >> n;

  if (__builtin_popcount(n) == 1) {
    cout << 1 << ENDL << n << ENDL;
    return;
  }

  vector<ll> ans;
  ROF (i, 64, 0) if ((n >> i) & 1) {
    ans.pb(n ^ (1ll << i));
  }
  if (ans.back() != n) ans.pb(n);
  cout << SZ(ans) << ENDL;
  for (auto &x : ans) cout << x << ' ';
  cout << ENDL;
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