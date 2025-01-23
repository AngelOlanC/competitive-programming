#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void solve() {
  i64 l, r, g;
  cin >> l >> r >> g;

  if (g >= l) {
    return;
  }

  i64 x = g, y = g;
  while (x < l) {
    x <<= 1;
  }
  while (y < l) {
    y *= 3;
  }
  if (x <= r && y <= r) {
    cout << x << ' ' << y << '\n';
  } else {
    cout << "-1 -1\n";
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