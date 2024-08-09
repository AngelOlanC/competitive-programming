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

  vi a, t, g, c;
  
  string s;
  cin >> s;
  FOR (i, 0, SZ(s)) {
    if (s[i] == 'A') {
      a.pb(i);
    }
    if (s[i] == 'T') {
      t.pb(i);
    }
    if (s[i] == 'G') {
      g.pb(i);
    }
    if (s[i] == 'C') {
      c.pb(i);
    }
  }
  
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;

    vector<tuple<int, int, char>> ans;
    ans.pb({-(upper_bound(ALL(a), r) - lower_bound(ALL(a), l)), 0, 'A'});
    ans.pb({-(upper_bound(ALL(t), r) - lower_bound(ALL(t), l)), 1, 'T'});
    ans.pb({-(upper_bound(ALL(g), r) - lower_bound(ALL(g), l)), 2, 'G'});
    ans.pb({-(upper_bound(ALL(c), r) - lower_bound(ALL(c), l)), 3, 'C'});

    sort(ALL(ans));

    for (auto &[len, x, c] : ans) {
      cout << c;
    }
    cout << ENDL;
  }

  return 0;
}