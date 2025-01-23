#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

using i64 = long long;

inline int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
    int a = 1, b = 1;
    for (int i = 1; i < n; ++i) {
      int c = add(mul(4, a), b), d = add(a, mul(2, b));
      swap(a, c);
      swap(b, d);
    }
    cout << add(a, b) << '\n';
  }

  return 0;
}