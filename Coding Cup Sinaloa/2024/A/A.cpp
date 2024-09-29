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
  string t;
  while (getline(cin, t)) {
    if (tolower(s[0]) == 'v') {
      for (auto c : t) {
        c = tolower(c);
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
          cout << toupper(c);
        } else {
          cout << tolower(c);
        }
      }
    } else {
      for (auto c : t) {
        c = tolower(c);
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
          cout << tolower(c);
        } else {
          cout << toupper(c);
        }
      }
    }
  }

  return 0;
}