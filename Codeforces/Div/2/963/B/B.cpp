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
  vi a(n);
  vi cnt(2);
  FOR (i, 0, n) {
    cin >> a[i];
    cnt[a[i] % 2]++;
  }
  if (!cnt[0] || !cnt[1]) {
    cout << 0 << ENDL;
    return;
  }
  sort(ALL(a));
  ll mximp = 0;
  FOR (i, 0, n) if (a[i] & 1) mximp = a[i];
  bool nice = 1;
  FOR (i, 0, n) if (a[i] % 2 == 0) {
    if (a[i] < mximp) {
      mximp += a[i];
    } else if (a[i] > mximp) {
      nice = 0;
      break;
    }
  }
  ll ans = cnt[0] + !nice; 
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