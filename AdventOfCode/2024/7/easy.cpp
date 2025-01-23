#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using i64 = long long;
vector<i64> a;
i64 target;
bool f(int i, i64 x) {
  if (x > target) {
    return false; 
  }
  if (i == a.size()) {
    return x == target;
  }
  return f(i + 1, x + a[i]) || f(i + 1, x * a[i]) || f(i + 1, stoll(to_string(x) + to_string(a[i])));
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string line;
  i64 ans = 0;
  while (getline(cin, line)) {
    a.clear();
    stringstream ss(line);
    char c;
    ss >> target >> c;
    while (ss.good()) {
      i64 x;
      ss >> x;
      a.push_back(x);
    }
    if (f(1, a[0])) {
      ans += target;
    }
  }
  cout << ans << '\n';
  return 0;
}