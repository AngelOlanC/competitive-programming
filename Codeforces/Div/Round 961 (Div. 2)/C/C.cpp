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
  vi a(n);
  for (auto &ai : a) cin >> ai;
  ll ans = 0, last = 0;
  FOR (i, 1, n) {
    if (a[i] == 1) {
      if (a[i - 1] != 1) {
        cout << -1 << ENDL;
        return;
      }
    }
    ll x = a[i], y = a[i - 1], c1 = 0, c2 = 0;
    while (x < y) {
      x *= x;
      c1++;
    }
    while (y * y <= x) {
      if (y == 1) {
        c2 = -1;
        break;
      }
      c2++;
      y *= y;
    }
    if (c1) last += c1;
    else if (c2 == -1) last = 0;
    else last = max(0LL, last - c2);
    ans += last;
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