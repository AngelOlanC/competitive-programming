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
  string s;
  cin >> n >> m >> s;

  vector<string> t(m);
  for (auto &ti : t) {
    int k;
    cin >> k >> ti;
    ti += char('z' + 1);
  }

  vi nxt[27];

  FOR (i, 0, m) nxt[t[i][0] - 'a'].pb(i);

  vi ind(m);
  for (auto &si : s) {
    vector<pi> waiting;
    for (auto &i : nxt[si - 'a']) {
      waiting.pb({t[i][++ind[i]] - 'a', i});
    }

    nxt[si - 'a'].clear();
    for (auto &[c, i] : waiting) {
      nxt[c].pb(i);
    }
  }

  FOR (i, 0, m) cout << (ind[i] + 1 == SZ(t[i])) << ENDL;

  return 0;
}