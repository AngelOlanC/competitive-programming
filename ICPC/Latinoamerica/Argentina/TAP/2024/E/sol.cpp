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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int N, P;
  cin >> N >> P;
  vi a(N), b(N), c(N);
  FOR (i, 0, N) cin >> a[i] >> b[i] >> c[i];
  vi p(N);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) { return a[i] })

  return 0;
}