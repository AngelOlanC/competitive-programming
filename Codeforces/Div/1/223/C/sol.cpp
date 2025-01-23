#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct FT {
  vector<int> s;
  FT(int n) : s(n) {}
  void upd(int pos, int dif) { // a[pos] += dif
    for (; pos < (int)s.size(); pos |= pos + 1) s[pos] += dif;
  }
  int query(int pos) { // sum of values in [0, pos)
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  const int n = (int)s.size();

  vector<int> match(n, -1);
  {
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        if (!st.empty()) {
          match[st.top()] = i;
          st.pop();
        }
      }
    }
  }

  int q;
  cin >> q;

  vector<tuple<int, int, int>> Q(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    Q[i] = {l - 1, r - 1, i};
  }

  sort(Q.begin(), Q.end());

  FT ft(n);
  for (int i = get<0>(Q[0]); i < n; ++i) {
    if (match[i] != -1) {
      ft.upd(match[i], 1);
    }
  }

  vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    auto [l, r, ind] = Q[i];
    if (i) {
      for (int j = get<0>(Q[i - 1]); j < l; ++j) {
        if (match[j] != -1) {
          ft.upd(match[j], -1);
        }
      }
    }
    ans[ind] = 2 * ft.query(r + 1);
  }

  for (int x : ans) {
    cout << x << '\n';
  }

  return 0;
}