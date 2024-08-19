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
  int n, k;
  cin >> n >> k;
  vi a(n);
  FOR (i, 0, n) cin >> a[i];
  sort(ALL(a));
  ll ans = 0;
  for (int i = n - 2; i >= 0; i -= 2) {
    int d = min(k, a[i + 1] - a[i]);
    a[i] += d, k -= d;
    ans += a[i + 1] - a[i];
  }
  if (n % 2 == 1) ans += a[0];
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