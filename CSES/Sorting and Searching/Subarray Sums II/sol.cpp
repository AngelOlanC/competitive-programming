#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  map<i64, int> mp;
  ++mp[0];
  i64 p = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    int y;
    cin >> y;
    p += y;
    ans += mp[p - x];
    ++mp[p];
  }
  cout << ans << '\n';

  return 0;
}