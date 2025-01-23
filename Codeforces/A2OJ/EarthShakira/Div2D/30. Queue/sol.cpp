#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<pair<int, int>> st;
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; --i) {
    auto it = st.upper_bound({a[i], 0});
    if (it == st.begin()) {
      ans[i] = -1;
      st.insert({a[i], i});
    } else {
      --it;
      ans[i] = it->second - i - 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}