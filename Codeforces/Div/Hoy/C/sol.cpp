#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

inline i64 sum(vector<i64>& v) {
  return accumulate(v.begin(), v.end(), 0ll);
}

void solve() {
  int n;
  cin >> n;

  vector<i64> a(n);
  for (i64& x : a) {
    cin >> x;
  }

  i64 ans = sum(a);
  while ((int)a.size() > 1) {
    vector<i64> d;
    for (int i = 1; i < (int)a.size(); ++i) {
      d.push_back(a[i] - a[i - 1]);
    }
    if (sum(d) < -sum(d)) {
      for (i64& x : d) {
        x = -x;
      }
    }
    a = d;
    ans = max(ans, sum(a));
  }
  ans = max(ans, a[0]);
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