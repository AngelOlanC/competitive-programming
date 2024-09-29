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
  int x;
  cin >> x;
  vi ans;
  for (int i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      ans.pb(i);
      x /= i;
    }
  }
  if (x != 1) ans.pb(x);
  int s = 41 - accumulate(ALL(ans), 0);
  if (s < 0) {
    cout << -1 << ENDL;
    return;
  }
  while (s--) ans.pb(1);
  cout << SZ(ans) << " ";
  FOR (i, 0, SZ(ans)) cout << ans[i] << " \n"[i == SZ(ans) - 1];
  assert(accumulate(ALL(ans), 0) == 41);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 1, tc + 1) {
    cout << "Case #" << test_case << ": ";
    solve(test_case + 1);
  }

  return 0;
}