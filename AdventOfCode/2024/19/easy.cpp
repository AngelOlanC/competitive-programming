#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

bool f(int i, string& s, set<string>& patterns) {
  int n = (int)s.size();
  if (i == n) {
    return true;
  }
  string curr = "";
  for (int j = i; j < n; ++j) {
    curr += s[j];
    if (patterns.find(curr) != patterns.end() && f(j + 1, s, patterns)) {
      return true;
    }
  }
  return false;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string line;
  getline(cin, line);
  
  stringstream ss(line);
  set<string> patterns;
  while (ss.good()) {
    string s;
    ss >> s;
    if (s.back() == ',') {
      s = s.substr(0, (int)s.size() - 1);
    }
    patterns.insert(s);
  }

  int ans = 0;
  while (cin >> line) {
    if (f(0, line, patterns)) {
      ++ans;
    }
  }
  cout << ans << '\n';

  return 0;
}