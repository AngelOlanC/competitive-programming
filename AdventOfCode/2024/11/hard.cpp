#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using i64 = long long;
map<pair<i64, int>, i64> mp;
i64 f(i64 x, int k) {
  if (k == 75) {
    return 1;
  }
  i64 &ans = mp[{x, k}];
  if (ans) {
    return ans;
  }
  if (x == 0) {
    return ans = f(1, k + 1);
  }
  string xs = to_string(x);
  int m = xs.size();
  if (m % 2 == 1) {
    return ans = f(x * 2024, k + 1);
  }
  return ans = f(stoll(xs.substr(0, m / 2)), k + 1) + f(stoll(xs.substr(m / 2)), k + 1);
}
signed main() {
  vector<int> a;
  int x;
  while (cin >> x) {
    a.push_back(x);
  }
  i64 ans = 0;
  for (int x : a) {
    ans += f(x, 0);
  }
  cout << ans << '\n';
  return 0;
}