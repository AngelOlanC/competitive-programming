#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void f(int i, int k, i64 xorSum, i64& ans, vector<i64>& a) {
  if (!k) {
    ans = max(ans, xorSum);
    return;
  }
  if (i + k - 1 >= (int)a.size()) {
    return;
  }
  f(i + 1, k - 1, xorSum ^ a[i], ans, a);
  f(i + 1, k, xorSum, ans, a);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<i64> a(n);
  for (i64& x : a) {
    cin >> x;
  }

  i64 ans = 0;
  
  i64 startingXor = 0;
  if (n - k < k) {
    for (i64& x : a) {
      startingXor ^= x;
    }
    k = n - k;
  }
  f(0, k, startingXor, ans, a);
  
  cout << ans << '\n';

  return 0;
}