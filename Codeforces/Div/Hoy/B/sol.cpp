#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] <= max(2 * i, 2 * (n - i - 1))) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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