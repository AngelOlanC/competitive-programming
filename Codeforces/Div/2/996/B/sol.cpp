#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n;
  cin >> n;
  
  vector<int> a(n), b(n);
  for (int& x : a) {
    cin >> x;
  }

  int below = 0, need, give = 1e9;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (b[i] > a[i]) {
      ++below;
      need = b[i] - a[i];
    } else {
      give = min(give, a[i] - b[i]);
    }
  }

  cout << (!below || (below == 1 && give >= need) ? "YES" : "NO") << '\n';
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