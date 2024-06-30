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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  string s;
  while (cin >> s) {
    int ans = 0, c = 0;
    for (auto &ch : s) {
      if (ch == '+') {
        c++;
        if (c > ans) {
          ans++;
        }
      }
      if (ch == '-') {
        if (c == 0) {
          ans++;
        } else {
          c--;
        }
      }
    }
    cout << ans << ENDL;
  }

  return 0;
}