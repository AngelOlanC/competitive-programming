#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  string s;
  cin >> s;

  cout << count(s.begin(), s.end(), '1') << '\n';
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