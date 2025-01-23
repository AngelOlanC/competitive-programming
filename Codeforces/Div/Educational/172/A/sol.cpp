#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int s = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s + a[i] > k) {
        break;
      }
      s += a[i];
    }
    cout << k - s << '\n';
  }
  return 0;
}