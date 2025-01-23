#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n;
  cin >> n;

  if (n == 6) {
    cout << "1 1 2 3 1 2\n";
    return;
  }

  if (n == 7) {
    cout << "1 1 2 1 2 3 2\n";
    return;
  }

  if (n == 8) {
    cout << "1 1 1 2 1 2 2 1\n";
    return;
  }

  if (n >= 9 && n < 15) {
    cout << "7 3 3 7 5 3 7 7 3 ";
    for (int i = 10; i <= n; ++i) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }

  cout << "15 8 8 8 15 5 8 1 15 5 8 15 15 15 8 ";
  for (int i = 16; i <= n; ++i) {
    cout << i << ' ';
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