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

  string s;
  cin >> s;

  vi ans;
  if (s[0] == s[1] && s[1] == s[2]) {
    ans.pb(0);
  }
  for (int i = 3; i < SZ(s); i += 3) {
    if (s[i] == s[i - 1]) {
      if (s[i] != s[i + 1] || s[i + 1] == s[i + 2]) {
        ans.pb(i);
        continue;
      }
      ans.pb(i + 1);
      s[i + 2] = s[i + 2] == '0' ? '1' : '0';
      continue;
    }
    if (s[i] == s[i + 1]) {
      ans.pb(i + 1);
      s[i + 2] = s[i + 2] == '0' ? '1' : '0';
    }
  }

  cout << SZ(ans) << ENDL;
  for (int x : ans) {
    cout << x + 1 << ' ';
  }
  cout << ENDL;

  return 0;
}