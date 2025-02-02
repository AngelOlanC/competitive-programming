#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy y de la Alexbriza

void solve() {
  int n;
  cin >> n;

  vector<int> cnt(3);
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 'X') {
        ++cnt[(i + j) % 3];
      }
    }
  }

  int mn = int(min_element(cnt.begin(), cnt.end()) - cnt.begin());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 'X' && (i + j) % 3 == mn) {
        a[i][j] = 'O';
      }
    }
    cout << a[i] << "\n";
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