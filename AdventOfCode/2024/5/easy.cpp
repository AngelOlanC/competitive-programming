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
  map<int, set<int>> before;
  map<int, set<int>> after;
  string line;
  int ans = 0;
  while (cin >> line) {
    if (line.size() <= 5) {
      stringstream ss(line);
      int x, y;
      char c;
      ss >> x >> c >> y;
      before[y].insert(x);
      after[x].insert(y);
    } else {
      vector<int> a;
      stringstream ss("," + line);
      while (ss.good()) {
        char c;
        int x;
        ss >> c >> x;
        a.push_back(x);
      }
      bool good = true;
      int n = a.size();
      set<int> st;
      for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int y : after[x]) {
          if (st.find(y) != st.end()) {
            good = false;
            break;
          }
        }
        st.insert(x);
      }
      st.clear();
      for (int i = n - 1; i >= 0; --i) {
        int x = a[i];
        for (int y : before[x]) {
          if (st.find(y) != st.end()) {
            good = false;
            break;
          }
        }
        st.insert(x);
      }
      if (good) {
        ans += a[a.size() / 2];
      }
    }
  }
  cout << ans << '\n';
  return 0;
}