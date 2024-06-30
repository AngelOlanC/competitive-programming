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

bool f(int i, deque<string>& v) {
  if (i + 3 >= SZ(v)) {
    return false;
  }

  if (v[i][0] == v[i + 3][0]) {
    v.erase(v.begin() + i, v.begin() + i + 4);
    return true;
  }

  if (v[i][1] == v[i + 3][1]) {
    v.erase(v.begin() + i + 3);
    v.erase(v.begin() + i);
    return true;
  }

  return false;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  deque<string> v;
  FOR (i, 0, 52) {
    string s;
    cin >> s;

    v.push_front(s);

    while (1) {
      bool b = 0;
      FOR (k, 0, 52) {
        if (f(k, v)) {
          b = 1;
          break;
        }
      }
      if (!b) {
        break;
      }
    }
  }

  cout << SZ(v);
  ROF (i, SZ(v), 0) {
    cout << ' ' << v[i];
  }
  cout << ENDL;

  return 0;
}