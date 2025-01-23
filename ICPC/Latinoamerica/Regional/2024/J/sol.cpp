#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int deg, n;
  cin >> deg >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  double last_right = a[0].first, tang = tan(deg * 2.0 * acos(-1.0) / 360.0), ans = 0;
  for (auto &[x, h] : a) {
    double len = (double)h / tang, add = x + len - max(last_right, (double)x);
    if (add > 0.0) {
      ans += add;
      last_right = x + len;
    }
  }
  cout << setprecision(9) << fixed;
  cout << ans << '\n';
  return 0;
}