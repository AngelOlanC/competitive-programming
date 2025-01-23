#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (i != j && abs(a[i] - a[j]) % k == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
      cout << i + 1 << '\n';
      return;
    }
  }
  cout << "NO\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}