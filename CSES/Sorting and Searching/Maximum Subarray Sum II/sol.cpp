#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, a, b;
  cin >> n >> a >> b;

  vector<i64> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    p[i] += p[i - 1];
  }

  multiset<i64> mst;
  i64 ans = -1e18;
  for (int i = a; i <= n; ++i) {
    mst.insert(p[i - a]);
    ans = max(ans, p[i] - *mst.begin());
    if (i >= b) {
      mst.erase(mst.find(p[i - b]));
    }
  }
  cout << ans << '\n';

  return 0;
}