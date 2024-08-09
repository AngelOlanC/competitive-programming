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
  string s;
  cin >> n >> s;
  ll ans = 0;
  int lp = 0, rp = 1;
  vi used(n);
  while (lp < n && rp < n) {
    if (used[lp]) {
      lp++;
      if (rp == lp) rp++;
      continue;
    }
    while (used[rp] || (rp % 2 && s[rp] != ')')) rp++;
    // cout << lp << ' ' << rp << ENDL;
    ans += rp - lp;
    used[rp] = 1;
    lp++, rp++;
    continue;
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