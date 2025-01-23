#include <bits/stdc++.h>
// Pura Gente del Coach Moy

using i64 = long long;

const int MOD = 16777216;

int prune(i64 x) {
  return x % MOD;
}

i64 mix(i64 x, i64 y) {
  return x ^ y;
}

int apply(i64 x, i64 y) {
  return prune(mix(x, y));
}

int transform(int x) {
  x = apply(x, x * 64ll);
  x = apply(x, x / 32);
  x = apply(x, x * 2048ll);
  return x;
}

int main() {
  int x;
  i64 ans = 0;
  while (std::cin >> x) {
    for (int i = 0; i < 2000; ++i) {
      x = transform(x);
    }
    ans += x;
  }
  std::cout << ans << '\n';
  return 0;
}