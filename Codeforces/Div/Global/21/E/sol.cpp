#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

constexpr int MOD = 1e9 + 7;

constexpr int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

constexpr int sub(int x, int y) {
  return x >= y ? x - y : x - y + MOD;
}

constexpr int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

constexpr int N = 5e5 + 5;

int inv[N], fact[N], invFact[N];

void prepare() {
  inv[1] = 1;
  for (int i = 2; i < N; ++i) {
    inv[i] = sub(MOD, mul(MOD / i, inv[MOD % i]));
  }
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  invFact[0] = invFact[1] = 1;
  for (int i = 2; i < N; i++) {
    invFact[i] = mul(invFact[i - 1], inv[i]);
  }
}

int comb(int n, int k) {
  if (n < k) {
    return 0;
  }
  return mul(mul(fact[n], invFact[k]), invFact[n - k]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  prepare();

  int n;
  cin >> n;

  vector<int> a(++n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = add(ans, comb(i + a[i], i + 1));
  }
  cout << ans << '\n';

  return 0;
}