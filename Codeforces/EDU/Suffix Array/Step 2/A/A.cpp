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
  string s;
  cin >> s;
  s += "$";
  int n = SZ(s);
  vi p(n), c(n), cnt(max(n, 256));
  FOR (i, 0, n) cnt[s[i]]++;
  FOR (i, 1, SZ(cnt)) cnt[i] += cnt[i - 1];
  FOR (i, 0, n) p[--cnt[s[i]]] = i;
  FOR (i, 1, n) c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  // FOR (i, 0, n) cout << p[i] << " \n"[i == n - 1];
  // FOR (i, 0, n) cout << c[i] << " \n"[i == n - 1];
  for (int k = 0; (1 << k) < n; ++k) {
    FOR (i, 0, n) p[i]=(p[i]-(1<<k)+n)%n;
    FOR (i, 0, SZ(cnt)) cnt[i] = 0;
    FOR (i, 0, n) ++cnt[c[i]];
    FOR (i, 1, SZ(cnt)) cnt[i] += cnt[i - 1];
    vi p2(n);
    ROF (i, n, 0) p2[--cnt[c[p[i]]]] = p[i];
    vi c2(n);
    FOR (i,1,n)c2[p2[i]]=c2[p2[i-1]]+(tie(c[p2[i]],c[(p2[i]+(1<<k))%n])!=tie(c[p2[i-1]],c[(p2[i-1]+(1<<k))%n]));
    p.swap(p2);
    c.swap(c2);
    // FOR (i, 0, n) cout << p[i] << " \n"[i == n - 1];
    // FOR (i, 0, n) cout << c[i] << " \n"[i == n - 1];
  }
  FOR (i, 0, n) cout << p[i] << " \n"[i == n - 1];
  return 0;
}