#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void solve() {
  i64 x;
  cin >> x;
  i64 cnt = 1;
  while (x > 3) {
    cnt <<= 1;
    x = x / 4;
  }
  cout << cnt << '\n';
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