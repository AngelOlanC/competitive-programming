#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

#define isOn(mask, b) ((mask >> b) & 1)

using i64 = long long;

struct XorBasis {
  int n;
  vector<i64> basis;

  XorBasis(int m) : basis(m) {}

  void insert(i64 mask) {
    for (int i = (int)basis.size() - 1; i >= 0; --i) {
      if (!isOn(mask, i)) {
        continue;
      }
      if (!basis[i]) {
        basis[i] = mask;
        return;
      }
      mask ^= basis[i];
    }
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<i64> a(n);
  i64 xorSum = 0;
  for (i64& x : a) {
    cin >> x;
    xorSum ^= x;
  }

  XorBasis xb(50);
  for (i64 x : a) {
    xb.insert(x & ~xorSum);
  }

  i64 ans = 0;
  for (int i = 49; i >= 0; --i) {
    if (!isOn(ans, i) && xb.basis[i]) {
      ans ^= xb.basis[i];
    }
  }

  ans <<= 1;
  ans += xorSum;

  cout << ans << '\n';

  return 0;
}