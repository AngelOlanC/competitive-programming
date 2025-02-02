#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy y de la Alexbriza

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

inline int mul(int x, int y) {
  return int((long long)x * y % MOD);
}

int be(int a, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    k >>= 1;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int d = a[j] - a[i];
      int l = int(lower_bound(a.begin(), a.begin() + i, a[i] - d) - a.begin());
      int r = int(a.end() - lower_bound(a.begin() + j + 1, a.end(), a[j] + d));
      ans = add(ans, be(2, l + r));
    }
  }
  cout << ans << '\n';

  return 0;
}