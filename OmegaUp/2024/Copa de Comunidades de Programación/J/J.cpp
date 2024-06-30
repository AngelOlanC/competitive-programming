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
  cin >> n;

  set<string> nombres;
  map<pair<string, string>, int> m;
  while (n--) {
    string nm, pr;
    int pts;
    cin >> nm >> pr >> pts;
    nombres.insert(nm);
    pair<string, string> p = {nm, pr};
    m[p] = max(m[p], pts);
  }

  vector<pair<int, string>> v;
  for (auto &nm : nombres) {
    int total = 0;
    for (auto &[p, pts] : m) {
      if (nm == p.first) {
        total += pts;
      }
    }
    v.pb({-total, nm});
  }

  sort(ALL(v));

  FOR (i, 0, 4) {
    cout << v[i].second << ENDL;
  }

  return 0;
}