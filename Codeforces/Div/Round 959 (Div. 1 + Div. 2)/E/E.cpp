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
  FOR (i, 0, n) {
    cin >> a[i];
    FOR (j, 1, a[i]) {
      int u;
      cin >> u;
    }
  }
  int ans = 0;
  ROF (i, 30, 0) {
    int cnt = 0;
    FOR (j, 0, n) cnt += (a[j] >> i) & 1;
    if (cnt >= 1) ans |= 1 << i;
    if (cnt >= 2) {
      ans |= (1 << i) - 1;
      break;
    }
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