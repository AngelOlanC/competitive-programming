#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

i64 f(i64 i, vector<i64>& dp, string& s, set<string>& patterns) {
  i64 n = (i64)s.size();
  if (i == n) {
    return true;
  }
  i64 &ans = dp[i];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  string curr = "";
  for (i64 j = i; j < n; ++j) {
    curr += s[j];
    if (patterns.find(curr) != patterns.end()) {
      ans += f(j + 1, dp, s, patterns);
    }
  }
  return ans;
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
      s = s.substr(0, (i64)s.size() - 1);
    }
    patterns.insert(s);
  }

  i64 ans = 0;
  while (cin >> line) {
    i64 n = (i64)line.size();
    vector<i64> dp(n, -1);
    ans += f(0, dp, line, patterns);
  }
  cout << ans << '\n';

  return 0;
}