#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 1; i <= n; ++i) {
      st.insert(i); 
    }
    for (int i = 0; i < n; ++i) {
      auto it = --st.end();
      if ((i + 1) % k == 0) {
        it = st.begin();
      }
      cout << *it << " \n"[i == n - 1];
      st.erase(it);
    }

  }

  return 0;
}