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

  int s, a, b, c;
  cin >> s >> a >> b >> c;

  if (a == 0 && b == 0 && c == 0) {
    cout << s << ' ' << 0 << ' ' << 0 << ENDL;
    return 0;
  } 
  long double below = a + b + c, sa = 1.0 * a * s / below, sb = 1.0 * b * s / below, sc = 1.0 * c * s / below;
  cout << setprecision(12) << fixed <<  sa << ' ' << sb << ' ' << sc << ENDL;

  return 0;
}