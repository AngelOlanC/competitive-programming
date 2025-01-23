#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int k;
  string s;
  cin >> k >> s;
  if (k == 2) {
    auto diff = [&](string t) -> int {
      int ret = 0;
      for (int i = 0; i < (int)s.size(); ++i) {
        ret += s[i] != t[i];
      }
      return ret;
    };
    string t = "";
    for (int i = 0; i < (int)s.size(); ++i) {
      t += '0' + (i % 2);
    }
    int ans = diff(t);
    string s_ans = t;
    t = "";
    for (int i = 0; i < (int)s.size(); ++i) {
      t += '0' + (i % 2 == 0);
    }
    int aux = diff(t);
    if (aux < ans) {
      ans = aux;
      s_ans = t;
    }
    cout << ans << ' ' << s_ans << '\n';
    return 0;
  }
  auto flip = [&](char c) -> char {
    return c == '0' ? '1' : '0';
  };
  int cnt = 0, ans = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (i && s[i] != s[i - 1]) {
      cnt = 1;
    } else {
      ++cnt;
    }
    if (cnt != k) {
      continue;
    }
    ++ans;
    if (i == (int)s.size() - 1 || s[i] == s[i + 1]) {
      s[i] = flip(s[i]);
    } else {
      s[i - 1] = flip(s[i - 1]);
    }
  }
  cout << ans << ' ' << s << '\n';
  return 0;
}