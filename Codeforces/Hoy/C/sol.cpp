#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve(int test_case) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  queue<int> q;
  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1') {
      q.push(i);
      continue;
    }
    ans += i + 1;
    if (!q.empty()) {
      q.pop();
    }
  }
  int half = q.size() / 2;
  for (int i = 0; i < half; ++i) {
    q.pop();
  }
  while (!q.empty()) {
    ans += q.front() + 1;
    q.pop();
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}