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
  int l, r, L, R;
  cin >> l >> r >> L >> R;
  if (l == L && r == R) {
    cout << R - L << ENDL;
    return;
  }
  int il = max(l, L), ir = min(r, R);
  if (il > ir) {
    cout << 1 << ENDL;
    return;
  }
  int ans = ir - il + (l != L) + (r != R);
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