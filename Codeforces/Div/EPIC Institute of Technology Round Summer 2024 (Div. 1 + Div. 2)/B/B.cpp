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
  vector<ll> a(n);
  for (auto &ai : a) {
    cin >> ai;
  }

  ll ans = 0, flying = 0;
  FOR (i, 1, n) {
    if (a[i] < a[i - 1]) {
      ll k = min(a[i - 1] - a[i], flying); 
      ans += k;
      a[i] += k;
      if (a[i] < a[i - 1]) {
        k = a[i - 1] - a[i];
        ans += 2 * k;
        flying += k;
        a[i] = a[i - 1];
      }
    }
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