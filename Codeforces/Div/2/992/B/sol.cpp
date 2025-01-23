#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int curr = 1, ans = 1;
  while (curr < n) {
    curr = (curr + 1) * 2;
    ++ans;
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}