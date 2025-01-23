#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  int n = (int)s.size();

  for (int x = 1; x <= n; ++x) {
    if (n % x) {
      continue;
    }
    bool ok = true;
    for (int i = x; i < n; ++i) {
      if (s[i] != s[i - x]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << x << ' ';
    }
  }
  cout << '\n';

  return 0;
}