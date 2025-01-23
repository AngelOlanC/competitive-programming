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

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  --x;
  --y;
  if (x > y) {
    swap(x, y);
  }

  auto prev = [&n](int x) -> int {
    int ret = x - 1;
    if (ret < 0) {
      ret += n;
    }
    return ret;
  };

  auto next = [&n](int x) -> int {
    int ret = x + 1;
    if (ret >= n) {
      ret -= n;
    }
    return ret;
  };

  if (abs(x - y) <= 1 || (min(x, y) == 0 && max(x, y) == n - 1)) {
    vector<int> a(n);
    a[x] = 0;
    for (int p1 = prev(x), p2 = next(x); true; p1 = prev(p1), p2 = next(p2)) {
      if (p1 == p2) {
        a[p1] = a[prev(p1)] ^ 1;
        break;
      }
      a[p1] = a[next(p1)] ^ 1;
      a[p2] = a[prev(p2)] ^ 1;
      if (prev(p1) == p2) {
        a[p1] = 2;
        break;
      }
    }
    for (int x : a) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }
  
  vector<int> a(n);
  a[x] = 0;
  a[y] = 1;
  for (int p1 = x + 1, p2 = y - 1; p1 <= p2; ++p1, --p2) {
    if (p1 == p2) {
      a[p1] = 2;
      break;
    }
    a[p1] = a[p1 - 1] ^ 1;
    a[p2] = a[p2 + 1] ^ 1;
  }

  for (int p1 = prev(x), p2 = next(y); true; p1 = prev(p1), p2 = next(p2)) {
    if (p1 == p2) {
      a[p1] = 2;
      break;
    }
    a[p1] = a[next(p1)] ^ 1;
    a[p2] = a[prev(p2)] ^ 1;
    if (prev(p1) == p2) {
      break;
    }
  }
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}