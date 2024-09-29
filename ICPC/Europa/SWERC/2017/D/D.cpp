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

constexpr int maxl = 50, maxn = 400, INF = 1e9;

int n;
int a[maxn];
string s;
string t[maxn];
int memo[maxl][maxl][maxn][maxl];

int dp(int l, int r, int w, int i) {
  if (i == SZ(t[w])) {
    if (l == r + 1) return a[w];
    return a[w] + dp(l, r, 0, 0);
  }
  if (l == r + 1) return -INF;
  int &ans = memo[l][r][w][i];
  if (ans != -1) return ans;
  ans = l != 0 && r != SZ(s) - 1 ? -INF : 0;
  if (w != n - 1) ans = max(ans, dp(l, r, w + 1, 0));
  for (int j = l; j <= r; ++j) if (s[j] == t[w][i]) {
    if (j == l) ans = max(ans, dp(j + 1, r, w, i + 1));
    else ans = max(ans, dp(j + 1, r, w, i + 1) + dp(l, j - 1, 0, 0));
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> s >> n;
  FOR (i, 0, n) {
    cin >> t[i] >> a[i];
    a[i + n] = a[i];
    t[i + n] = t[i];
    reverse(ALL(t[i + n]));
  }
  n += n;
  
  memset(memo, -1, sizeof memo);

  cout << dp(0, SZ(s) - 1, 0, 0) << ENDL;

  return 0;
}         