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
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 0 << ENDL;
    return;
  }
  k = max(0, k - n);
  int ans = 1;
  n--;
  while (k) {
    k = max(0, k - n);
    ans++;
    if (!k) break;
    k = max(0, k - n);
    n--;
    ans++;
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