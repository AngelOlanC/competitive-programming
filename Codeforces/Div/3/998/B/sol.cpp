#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n, m;
  cin >> n >> m;
  
  vector<int> row(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      row[x] = i;
    }
  }

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = row[i];
  }

  for (int i = 0; i < n * m; ++i) {
    if (row[i] != p[i % n]) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int x : p) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
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