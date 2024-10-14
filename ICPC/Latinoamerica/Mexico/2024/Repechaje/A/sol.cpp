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
  vector<pair<string, string>> S(n);
  FOR (i, 0, n) {
    string s;
    cin >> s;
    string t = s;
    sort(ALL(t));
    S[i] = {t, s};
  }

  sort(ALL(S));

  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    string t = s;
    sort(ALL(t));
    cout << upper_bound(ALL(S), make_pair(t, s)) - S.begin() << ENDL;
  }

  return 0;
}