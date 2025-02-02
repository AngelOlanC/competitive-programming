#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int& x : a) {
      cin >> x;
    }
    for (int& x : b) {
      cin >> x;
    }

    int p = a[0];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> c(m);
    for (int i = m - 1, j = n - 1; b[i] > p && i >= 0; --i) {
      while (j != -1 && a[j] >= b[i]) {
        --j;
      }
      c[i] = n - j - 1;
    }
    sort(c.begin(), c.end());

    for (int k = 1; k <= m; ++k) {
      i64 ans = 0;
      for (int j = k - 1; j < m; j += k) {
        ans += c[j] + 1;
      }
      cout << ans << " \n"[k == m];
    }
  }

  return 0;
}