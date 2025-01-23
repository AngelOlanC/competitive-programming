#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  map<int, int> mp;
  for (int& x : a) {
    cin >> x;
    ++mp[x];
  }

  int ans = 0;
  for (auto [x, c] : mp) {
    ans += min(c, mp[k - x]);
  }
  ans >>= 1;
  
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
