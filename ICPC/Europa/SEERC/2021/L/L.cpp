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
  int n;
  string s;
  cin >> n >> s;
  vi c(3);
  FOR (i, 0, SZ(s)) c[s[i] - 'A']++;
  if (c[0] == c[1] && c[1] == c[2]) {
    cout << 0 << ENDL;
    return 0;
  }
  if (max({c[0], c[1], c[2]}) == 3 * n) {
    cout << 2 << ENDL;
    FOR (i, 0, 3) if (c[i] == 0) {
      cout << i * n + 1 << ' ' << (i + 1) * n << ' ' << char('A' + i) << ENDL;
    }
    return 0;
  }
  if ((c[0] >= n) + (c[1] >= n) + (c[2] >= n) == 2) {
    char ans_c;
    vector<pi> need;
    FOR (i, 0, 3) {
      if (c[i] >= n) need.pb({i, c[i] - n});
      else ans_c = char('A' + i);
    }
    vector<vi> occ(3);
    ROF (i, SZ(s), 0) {
      occ[s[i] - 'A'].pb(i);
      auto [c1, q1] = need[0];
      auto [c2, q2] = need[1];
      if (SZ(occ[c1]) < q1 || SZ(occ[c2]) < q2) continue;
      int l1 = SZ(occ[c1]) >= q1 ? end(occ[c1])[-q1] : i;
      int r1 = SZ(occ[c1]) > q1 ? end(occ[c1])[-q1 - 1] : 3 * n - 1;
      int l2 = SZ(occ[c2]) >= q2 ? end(occ[c2])[-q2] : i;
      int r2 = SZ(occ[c2]) > q2 ? end(occ[c2])[-q2 - 1] : 3 * n - 1;
      if (max(l1, l2) <= min(r1, r2)) {
        cout << 1 << ENDL;
        cout << i + 1 << ' ' << max(l1, l2) + 1 << " " << ans_c << ENDL;
        return 0;
      }
    }
  }
  cout << 2 << ENDL;
  int pivot;
  FOR (i, 0, 3) if (c[i] <= c[(i + 1) % 3] && c[i] <= c[(i + 2) % 3]) pivot = i;
  FOR (i, 0, SZ(s)) if (s[i] - 'A' != pivot) {
    c[pivot]++;
    c[s[i] - 'A']--;
    if (max(c[(pivot + 1) % 3], c[(pivot + 2) % 3]) == n) {
      cout << "1 " << i + 1 << ' ' << char('A' + pivot) << ENDL;
      break;
    }
  }
  int mn;
  FOR (i, 0, 3) if (c[i] < n) mn = i;
  cout << 1 << ' ' << n - c[mn] << ' ' << char('A' + mn) << ENDL;
  return 0;
}