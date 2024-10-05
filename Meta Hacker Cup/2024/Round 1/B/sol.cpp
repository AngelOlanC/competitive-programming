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

constexpr int maxn = 1e7 + 1;

int ans[maxn];

void solve() {
  int n;
  cin >> n;
  cout << ans[n] << ENDL;
}

int is_prime[maxn];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FOR (i, 2, maxn) is_prime[i] = 1;
  FOR (i, 2, maxn) if (is_prime[i]) for (int j = i * 2; j < maxn; j += i) is_prime[j] = 0;

  ans[5] = 2;
  int last = 5;
  FOR (i, 6, maxn) {
    ans[i] += ans[i - 1];
    if (!is_prime[i]) continue;
    ans[i] += last == i - 2;
    last = i;
  }

  int t;
  cin >> t;
  FOR (i, 1, t + 1) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}