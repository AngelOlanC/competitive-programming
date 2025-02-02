#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy y de la Alexbriza

using i64 = long long;

constexpr int MOD = 1e9 + 7;

int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

int be(int a, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    n >>= 1;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  int oddSum = 0, mx = 0, pot = 0;
  cout << a[0] << ' ';
  for (int i = 1; i < n; ++i) {
    int k = i;
    if (a[i] > a[mx]) {
      k = mx;
      mx = i;
    }
    while (a[k] % 2 == 0) {
      a[k] >>= 1;
      ++pot;
    }
    oddSum = add(oddSum, a[k]);
    cout << add(oddSum, mul(be(2, pot), a[mx])) << " \n"[i == n - 1];
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