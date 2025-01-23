#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << (abs(a - b) % 2 == 0 ? "YES" : "NO") << '\n';
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