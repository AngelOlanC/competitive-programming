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
  int n;
  cin >> n;

  auto ask = [&](string q) -> int {
    cout << "? " << q << endl;
    int x;
    cin >> x;
    return x;
  };

  string t = "";
  bool start = true;
  FOR (i, 0, n) {
    if (start) {
      string q = "0" + t;
      if (ask(q)) {
        t = q;
        continue;
      }
      q = "1" + t;
      if (ask(q)) {
        t = q;
        continue;
      }
      start = false;
    }
    string q = t + "0";
    if (ask(q)) {
      t = q;
      continue;
    }
    q = t + "1";
    t = q;
  }
  cout << "! " << t << endl;
}

signed main() {
  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}