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

  for (int i = 1; i < n; ++i) {
    if (a[i - 1] > a[i]) {
      cout << "NO\n";
      return;
    }
    a[i] -= a[i - 1];
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