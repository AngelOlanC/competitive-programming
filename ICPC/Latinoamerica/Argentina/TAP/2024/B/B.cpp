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
  int n;
  cin >> n;
  vi pd;
  int m = n;
  for (int i = 2; i * i <= n; ++i) {
    if (m % i == 0) {
      while (m % i == 0) m /= i;
      pd.pb(i);
    }
  }
  if (m != 1) pd.pb(m);
  cout << SZ(pd) << ENDL;
  for (auto &d : pd) cout << 1 << ' ' << n / d << ENDL;
  return 0;
}