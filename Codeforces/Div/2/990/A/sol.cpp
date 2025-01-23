#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int placed = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      placed += x;
      int sq = sqrt(placed);
      if (sq * sq == placed && sq % 2 == 1) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}