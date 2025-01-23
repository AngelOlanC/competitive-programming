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
    cout << (n % 33 == 0 ? "YES" : "NO") << '\n';
  }

  return 0;
}