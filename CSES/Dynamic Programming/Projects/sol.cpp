#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<int, vector<pair<int, int>>> mp;
  for (int i = 0; i < n; ++i) {
    int a, b, p;
    cin >> a >> b >> p;
    mp[-a].emplace_back(b, p);
  }

  set<pair<int, i64>> st;

  st.emplace(1e9 + 1, 0);

  for (auto& [a, v] : mp) {
    i64 val = 0;
    for (auto [b, p] : v) {
      val = max(val, p + st.lower_bound(make_pair(b + 1, 0))->second);
    }
    if (val > st.lower_bound(make_pair(-a + 1, 0))->second) {
      st.emplace(-a, val);
    }
  }
  cout << st.begin()->second << '\n';

  return 0;
}