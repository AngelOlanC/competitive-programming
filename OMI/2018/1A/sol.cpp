#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ull = unsigned ll;
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

  vector<ull> pot26(16);
  pot26[0] = 1;
  FOR (i, 1, 16) pot26[i] = pot26[i - 1] * 26;
  int op;
  cin >> op;
  if (op == 0) {
    ll x;
    cin >> x;
    --x;
    string s = "";
    bool flag = 0;
    ROF (i, 16, 0) {
      if (x >= pot26[i]) {
        int k = x / pot26[i];
        s += char('A' + k - 1);
        x -= pot26[i] * k;
        flag = 1;
      } else if (flag) s += "A";
    }
    cout << s << ENDL;
    return 0;
  }
  string s;
  cin >> s;
  reverse(ALL(s));
  ll x = 0;
  FOR (i, 0, SZ(s)) x += pot26[i] * (s[i] - 'A' + 1);
  cout << x << ENDL;
  return 0;
}