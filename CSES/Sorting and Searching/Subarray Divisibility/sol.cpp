#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

inline int add(const int x, const int y, const int m) {
  return x + y < m ? x + y : x + y - m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> cnt(n);
  ++cnt[0];
  int p = 0;
  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    p = add(p, add(x % n, n, n), n);
    ans += cnt[p];
    ++cnt[p]; // p = x (mod n)
  }
  cout << ans << '\n';

  return 0;
}