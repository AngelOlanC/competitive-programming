#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int l, r;
  cin >> l >> r;

  int highest = 31 - __builtin_clz(l ^ r);

  int a = l | ((1 << highest) - 1);
  int b = a + 1;
  int c = r;
  if (c == a || c == b) {
    --c;
  }
  if (c == a || c == b) {
    --c;
  }
  cout << a << ' ' << b << ' ' << c << '\n';
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