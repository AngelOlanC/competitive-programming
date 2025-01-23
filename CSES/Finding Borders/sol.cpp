#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

vector<int> getPrefixFunction(string& s) {
  vector<int> p((int)s.size());
  p[0] = 0;
  for (int i = 1; i < (int)s.size(); ++i) {
    p[i] = p[i - 1];
    while (p[i] && s[p[i]] != s[i]) {
      p[i] = p[p[i] - 1];
    }
    if (s[p[i]] == s[i]) {
      ++p[i];
    }
  }
  return p;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  vector<int> p = getPrefixFunction(s);

  vector<int> ans;
  for (int j = p.back(); j; j = p[j - 1]) {
    ans.push_back(j);
  }
  
  reverse(ans.begin(), ans.end());
  
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}