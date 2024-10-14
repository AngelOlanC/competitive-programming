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
  vi b(n), p(n), f(n);
  FOR (i, 0, n) cin >> b[i];
  FOR (i, 0, n) cin >> p[i];
  FOR (i, 0, n) cin >> f[i];

  vector<vi> dp_joy(780,);

  vector<vi> dp_fame(780);


  return 0;
}