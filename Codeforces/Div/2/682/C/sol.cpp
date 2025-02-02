#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy y de la Alexbriza

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      if (x % 2 != (i + j) % 2) {
        ++x;
      }
      cout << x << " \n"[j == m - 1];
    }
  }
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