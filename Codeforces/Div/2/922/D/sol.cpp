#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

bool f(i64 x, vector<i64>& a) {
  const int n = (int)a.size();

  multiset<i64> mst;
  mst.insert(0);
  i64 s = 0;
  vector<i64> dp(n);
  int r = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    while (s - a[r] > x) {
      s -= a[r];
      mst.erase(mst.find(dp[r]));
      --r;
    }
    dp[i] = a[i] + *mst.begin();
    mst.insert(dp[i]);
    s += a[i];
  }

  s = 0;
  for (int i = 0; i < n && s <= x; ++i) {
    if (dp[i] <= x) {
      return true;
    }
    s += a[i];
  }
  return false;
}

void solve() {
  int n;
  cin >> n;

  vector<i64> a(n);
  for (i64& x : a) {
    cin >> x;
  }
  a.push_back(0);

  i64 l = 1, r = 1e14;
  while (l < r) {
    i64 m = (l + r) >> 1;
    if (f(m, a)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << '\n';
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