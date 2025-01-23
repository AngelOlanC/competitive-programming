#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve(int t) {
  string s;
  cin >> s;

  map<int, int> m;
  FOR (i, 0, SZ(s)) {
    m[s[i]] = i;
  }
  if (SZ(m) == 1) {
    cout << "NO" << ENDL;
    return;
  }
  cout << "YES" << ENDL;
  auto it = m.begin();
  int i = it->second;
  it++;
  int j = it->second;
  swap(s[i], s[j]);
  cout << s << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;
  FOR (i, 0, t) {
    solve(t + 1);  
  }

  return 0;
}