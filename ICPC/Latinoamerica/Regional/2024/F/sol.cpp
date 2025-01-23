#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> k >> n;
  if (k > (n + 1) / 2 || k < (n + 2) / 3) {
    cout << "*\n";
    return 0;
  }
  vector<bool> ans(n);
  int i = 1, res = n;
  while (k != (res + 1) / 2) {
    ans[i] = true;
    i += 3;
    --k;
    res -= 3;
  }
  --i;
  while (k--) {
    ans[i] = true;
    i += 2;
  }
  for (i = 0; i < n; ++i) {
    cout << "-X"[ans[i]];
  }
  cout << '\n';
  return 0;
}