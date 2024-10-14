#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using vi = vector<int>;
using i128 = __int128_t;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr i128 INF = 4e18;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  string sa = to_string(a), sb = to_string(b);
  FOR (mask, 1, (1 << SZ(sb))) {
    string snb = "";
    vi out(10, 0);
    FOR (i, 0, SZ(sb)) {
      if ((mask >> i) & 1) snb += sb[i];
      else ++out[sb[i] - '0'];
    }
    if (snb[0] == '0') continue;
    ll nb = stoll(snb);
    i128 x = (i128)c * nb;
    if (x % d || x >= INF * d) continue;
    string sna = to_string(ll(x / d));
    int j = 0;
    for (auto c : sa) {
      if (j < SZ(sna) && c == sna[j]) ++j;
      else --out[c - '0'];
    }
    if (!*max_element(ALL(out)) && j == SZ(sna)) {
      cout << "possible" << ENDL;
      cout << sna << ' ' << snb << ENDL;
      return 0;
    } 
  }
  cout << "impossible" << ENDL;

  return 0;
}