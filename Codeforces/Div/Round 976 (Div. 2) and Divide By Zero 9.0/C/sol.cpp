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
  ll b, c, d;
  cin >> b >> c >> d;
  ll a = 0;
  for (int i = 0; i < 61; ++i) {
    bool onB = (b >> i) & 1, onC = (c >> i) & 1, onD = (d >> i) & 1;
    if (onD) {
      if (onB) continue;
      if (onC) break;
      a |= 1ll << i;
      continue;
    }
    if (!onB) continue;
    if (!onC) break;
    a |= 1ll << i;
  }
  cout << ((a | b) - (a & c) == d ? a : -1) << ENDL;
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