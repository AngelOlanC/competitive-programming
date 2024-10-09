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

constexpr int maxn = 1e7 + 1;

int cnt_pf[maxn];
int pf[maxn][10];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FOR (i, 2, maxn) if (!cnt_pf[i]) for (int j = i; j < maxn; j += i) pf[j][cnt_pf[j]++] = i;

  int n;
  cin >> n;
  vi a(n);
  FOR (i, 0, n) cin >> a[i];

  vi L(n, -1), R(n, n);
  {
    vi lst(maxn, -1);
    FOR (i, 0, n) FOR (j, 0, cnt_pf[a[i]]) {
      int x = pf[a[i]][j];
      L[i] = max(L[i], lst[x]);
      lst[x] = i;
    }
    fill(ALL(lst), n);
    ROF (i, n, 0) FOR (j, 0, cnt_pf[a[i]]) {
      int x = pf[a[i]][j];
      R[i] = min(R[i], lst[x]);
      lst[x] = i;
    }
  }

  auto can_be_root = [&](int i, int l, int r) -> bool {
    return L[i] < l && R[i] > r;
  };

  vi p(n);
  auto solve = [&](auto &&self, int l, int r, int par) -> bool {
    if (l > r) return true;
    for (int k = 0; l + k <= r - k; ++k) {
      if (can_be_root(l + k, l, r)) {
        p[l + k] = par;
        return self(self, l, l + k - 1, l + k) && self(self, l + k + 1, r, l + k);
      }
      if (can_be_root(r - k, l, r)) {
        p[r - k] = par;
        return self(self, l, r - k - 1, r - k) && self(self, r - k + 1, r, r - k);
      }
    }
    return false;
  };

  if (!solve(solve, 0, n - 1, -1)) {
    cout << "impossible\n";
    return 0;
  }
  FOR (i, 0, n) cout << p[i] + 1 << " \n"[i == n - 1];
  return 0;
}