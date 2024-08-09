#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve(int test_case) {
  string s;
  cin >> s;
  bool b = 1;
  FOR (i, 0, SZ(s) - 1) {
    cout << s[i];
    if (b && s[i] == s[i + 1]) {
      if (s[i] == 'a') cout << "b";
      else cout << "a";
      b = 0;
    }
  }
  cout << s.back();
  if (b) {
    if (s.back() == 'a') cout << "b";
    else cout << "a";    
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}