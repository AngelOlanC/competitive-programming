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
  int n, m;
  cin >> n >> m;
  vi a(n);
  FOR (i, 0, n) cin >> a[i];
  vi b(m);
  FOR (i, 0, m)cin >> b[i];
  FOR (it, 0, 2) {
    int j = 0;
    FOR (i, 0, n) if (a[i] == b[0]) {
      j = i;
      break;
    }
    bool good = 1;
    FOR (k, 0, m) if (a[(j + k) % n] != b[k]) {
      good = 0;
      break;
    }
    if (good) {
      cout << 1 << ENDL;
      return 0;
    }
    reverse(ALL(a));
  }
  cout << 0 << ENDL;
  return 0;
}