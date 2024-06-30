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

int calc(string s) {
  int ans = 0;
  for (auto &c : s) {
    if (c >= '0' && c <= '9') {
      ans += c - '0';
    }
    if (c >= 'a' && c <= 'z') {
      ans += 10 + c - 'a';
    }
    if (c >= 'A' && c <= 'Z') {
      ans += (10 + c - 'A') * 2;
    }
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  int ana = calc(s), carolina = calc(t);

  if (ana > carolina) {
    cout << "Ana " << ana << ENDL;
    return 0;
  }
  cout << "Carolina " << carolina << ENDL;

  return 0;
}