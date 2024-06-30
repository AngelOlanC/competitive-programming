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

  int n;
  cin >> n;
  int p[n];
  FOR (i, 0, n) {
    cin >> p[i];
  }

  int v[5];
  FOR (i, 0, 5) {
    cin >> v[i];
  }

  ll ans = 0, c[5];
  memset(c, 0, sizeof c);
  FOR (i, 0, n) {
    ll val = ans + p[i];
    ROF (j, 5, 0) {
      ll x = val / v[j];
      val -= x * v[j];
      c[j] += x;
    }
    ans = val;
  }

  FOR (i, 0, 5) {
    cout << c[i] << ' ';
  }
  cout << ENDL << ans << ENDL;

  return 0;
}