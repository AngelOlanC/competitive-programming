#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int ones = 0, not_ones = 0;
    for (auto [x, c] : cnt) {
      if (c == 1) {
        ++ones;
      } else {
        ++not_ones;
      }
    }
    int ans = (ones + 1) / 2 * 2 + not_ones;
    cout << ans << '\n';
  }
  return 0;
}