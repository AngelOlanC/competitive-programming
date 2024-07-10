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
  vi a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  vi as(ALL(a)), bs(ALL(b));
  sort(ALL(as));
  sort(ALL(bs));
  if (as != bs) {
    cout << "NO" << ENDL;
    return;
  }

  if (n == 1) {
    cout << "YES" << ENDL;
    return;
  }
  
  map<int, int> pa, pb;

  FOR (i, 0, n) {
    pa[a[i]] = i;
    pb[b[i]] = i;
  }

  auto myswap = [](int i, int j, vi& v, map<int, int>& m) -> void {
    swap(v[i], v[j]);
    swap(m[v[i]], m[v[j]]);
  };

  FOR (i, 0, n) {
    if (i == n - 2) break;
    if (a[i] == b[i]) continue;
    int pos = pb[a[i]];
    if (pos != n - 1) {
      myswap(i, pos, b, pb);
      myswap(i + 1, i + 1 + pos - i, a, pa);
      continue;
    }
    myswap(n - 2, n - 1, b, pb);
    myswap(i + 1, i + 2, a, pa);
    
    pos--;
    myswap(i, pos, b, pb);
    myswap(i + 1, i + 1 + pos - i, a, pa);
  }
  bool can = end(a)[-1] == end(b)[-1] && end(a)[-2] == end(b)[-2];
  cout << (can ? "YES" : "NO") << ENDL;
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