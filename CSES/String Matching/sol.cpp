#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int kmp(string& s, string& t) {
  vector<int> p((int)t.size());
  p[0] = 0;
  for (int i = 1; i < (int)t.size(); ++i) {
    p[i] = p[i - 1];
    while (p[i] && t[p[i]] != t[i]) {
      p[i] = p[p[i] - 1];
    }
    if (t[p[i]] == t[i]) {
      ++p[i];
    }
  }
  // for (int x : p) {
  //   cout << x << ' ';
  // }
  // cout << '\n';
  // return 0;
  int j = 0, ans = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    while (j && t[j] != s[i]) {
      j = p[j - 1];
      // cout << j << '\n';
    }
    if (t[j] == s[i] && ++j == (int)t.size()) {
      ++ans;
      j = p[j - 1];
    }
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s, t;
  cin >> s >> t;

  cout << kmp(s, t) << '\n';

  return 0;
}