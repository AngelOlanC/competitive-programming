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

  int n, m, o;
  cin >> n >> m >> o;
  
  vi I(n);
  FOR (i, 0, n) cin >> I[i];

  vector<vector<pi>> D(m);
  FOR (k, 0, m) {
    int c;
    cin >> c;
    while (c--) {
      int i, q;
      cin >> i >> q;
      D[k].pb({i - 1, q});
    }
  }

  vector<vi> O(o);
  FOR (i, 0, o) {
    int c;
    cin >> c;
    while (c--) {
      int dish;
      cin >> dish;
      O[i].pb(dish - 1);
    }
  }

  FOR (k, 0, o) {
    bool ok = 1;
    for (auto &d : O[k]) {
      for (auto &[i, q] : D[d]) {
        if (I[i] >= q) I[i] -= q;
        else ok = 0;
      }
    }
    if (!ok) {
      cout << k << ENDL;
      return 0;
    }
  }
  cout << o << ENDL;
  return 0;
}