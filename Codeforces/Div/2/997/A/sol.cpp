#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n, m;
  cin >> n >> m;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ans += 4 * m;
    if (i) {
      ans -= 2 * (m - x + m - y);
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}