#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

inline int add(int a, int b, const int MOD) {
  return a + b < MOD ? a + b : a + b - MOD;
}

inline int mul(int a, int b, const int MOD) {
  return int((i64)a * b % MOD);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ans = add(ans, mul(x, mul(i + 1, n - i, m), m), m);
  }
  cout << ans << '\n';

  return 0;
}