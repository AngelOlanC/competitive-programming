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

#define N 100005

int n, m;
int a[N];

int can(int d) {
  int last = a[0], k = m - 1;
  FOR (i, 1, n) {
    if (!k) {
      return true;
    }
    if (a[i] - last >= d) {
      last = a[i];
      k--;
    }
  }
  return k == 0;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  FOR (i, 0, n) {
    cin >> a[i];
  }
  sort(a, a + n);
  cin >> m;

  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }

  cout << l << ENDL;

  return 0;
}