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

  int n;
  while (cin >> n) {
    ll a = n * (n + 1) / 2, b = 0;
    FOR (i, 2, n + 1) {
      int k = n - i + 1;
      a += 1ll * k * (k + 1);
    }
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        b += 1ll * (n - i) * (n - j);
      }
    }
    cout << a << ' ' << b << ENDL;
  }

  return 0;
}