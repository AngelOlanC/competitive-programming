#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int ans[105];
  FOR (n, 1, 100) {
    ans[n] = 0;
    FOR (i, 1, n + 1) {
      FOR (j, i, n + 1) {
        FOR (k, j, n + 1) {
          if (i + j + k <= n && i + j > k && i + k > j && j + k > i) {
            ans[n]++;
          }
        }
      }
    }
    cout << n << ' ' << ans[n] << ' ' << ans[n] - ans[n - 1] << ENDL;
  }

  return 0;
}