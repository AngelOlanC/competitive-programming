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
  ll ans = 0;
  stack<pair<ll, int>> st;
  // cout << "case\n";
  FOR (i, 0, n) {
    int x, y;
    cin >> x >> y;
    st.push({x,y});
    while (1) {
      auto [a, b] = st.top(); st.pop();
      ll mx = 0;
      while (!st.empty() && st.top().second != b && st.top().first <= a) {
        mx = st.top().first;
        st.pop();
      } 
      if (!st.empty() && st.top().second == b) {
        auto [aa, bb] = st.top(); st.pop();
        // cout << ENDL <<  i << ' ' << aa << ' ' << bb << ENDL;
        ans = max(ans, aa + a - mx);
        st.push({aa + a - mx, bb});
      } else {
        ans = max(ans, (ll)a);
        st.push({a, b});
        break;
      }
    }
    cout << ans << " \n"[i == n - 1];
  }
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