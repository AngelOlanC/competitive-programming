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

  int low = 0, upp = 0;
  for (auto &c : s) {
    low += c >= 'a' && c <= 'z';
    upp += c >= 'A' && c <= 'Z';
  }
  for (auto &c : s) {
    if (low > upp) {
      c = tolower(c); 
    } else {
      c = toupper(c);
    }
  }

  cout << s << ENDL;

  return 0;
}