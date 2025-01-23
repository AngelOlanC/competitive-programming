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
    vector<int> l(n), r(n), p(n);
    map<pair<int, int>, int> cnt_ranges;
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
      ++cnt_ranges[{l[i], r[i]}];
      p[i] = i;
    }
    vector<int> ans(n);
    for (int side = 0; side < 2; ++side) {
      sort(p.begin(), p.end(), [&](int i, int j) -> bool {
        return l[i] < l[j] || (l[i] == l[j] && r[i] > r[j]);
      });
      set<int> ends;
      for (int i : p) {
        auto it = ends.lower_bound(r[i]);
        if (it != ends.end()) {
          ans[i] += *it - r[i];
        }
        ends.insert(r[i]);
      }
      for (int i = 0; i < n; ++i) {
        l[i] = 1e9 - l[i];
        r[i] = 1e9 - r[i];
        swap(l[i], r[i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (cnt_ranges[{l[i], r[i]}] > 1) {
        ans[i] = 0;
      }
    }
    for (int x : ans) {
      cout << x << '\n';
    }
  }
  return 0;
} 