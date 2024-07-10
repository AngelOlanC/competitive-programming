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

using ld = long double;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<ld> v(n), vi(n);
  FOR (i, 0, n) {
    cin >> v[i];
    vi[i] = 1 - v[i];
  }

  vector<ld> dp(n + 1);
  

  cout << setprecision(15) << fixed << ans << ENDL;

  return 0;
}