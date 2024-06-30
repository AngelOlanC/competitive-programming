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

  string s;
  cin >> s;

  ll ans[2] = {0, 0};
  ans[1] += SZ(s);

  ll cnt[2][2] = {{0, 0}, {0, 0}};
  ROF (i, SZ(s), 0) {
    int c = s[i] - 'a', b = i % 2;
    ans[0] += cnt[c][!b];
    ans[1] += cnt[c][b];
    cnt[c][b]++;
  }
  cout << ans[0] << ' ' << ans[1] << ENDL;

  return 0;
}