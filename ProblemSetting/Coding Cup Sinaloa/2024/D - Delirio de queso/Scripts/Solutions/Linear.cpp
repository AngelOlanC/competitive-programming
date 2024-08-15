#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int binaryExponenciation(int x, long long k) {
  if (k == 0) {
    return 1;
  }
  int y = binaryExponenciation(x, k / 2);
  y = (long long)y * y % MOD;
  if (k % 2 == 1) {
    y = (long long)y * x % MOD;
  }
  return y;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, a, b;
  long long k;
  cin >> n >> m >> k >> a >> b;

  vector<int> factorial(n + m + 1);
  factorial[0] = 1;
  for (int i = 1; i <= n + m; ++i) {
    factorial[i] = (long long)factorial[i - 1] * i % MOD;
  }

  vector<int> inverse(n + m + 1);
  inverse[1] = 1;
  for (int i = 2; i <= n + m; ++i) {
    inverse[i] = MOD - (long long)(MOD / i) * inverse[MOD % i] % MOD;
  }

  vector<int> inverse_factorial(n + m + 1);
  inverse_factorial[0] = inverse_factorial[1] = 1;
  for (int i = 2; i <= n + m; ++i) {
    inverse_factorial[i] = (long long)inverse_factorial[i - 1] * inverse[i] % MOD;
  }

  auto combinations = [&](int n, int k) -> int {
    if (n < k) return 0;
    return (long long)factorial[n] * inverse_factorial[k] % MOD * inverse_factorial[n - k] % MOD;
  };

  int startToCheese = combinations(a + b - 2, a - 1);
  int cheeseToEnd = combinations(n - a + m - b, n - a);
  int answerSingleCase = (long long)startToCheese * cheeseToEnd % MOD;
  int answer = binaryExponenciation(answerSingleCase, k);

  cout << answer << '\n';

  return 0;
}