#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int a[100005];
int n, k;

int eval(int i) {
  int mn = 1e9, mx = 0;
  FOR (j, 0, n) {
    int d = max(1, min(k, a[j] / i));
    int x = a[j] / d;
    mn = min(mn, x);
    mx = max(mx, x);
  }
  return mn <= mx ? mx - mn : -1;
}

void solve(int t) {
  cin >> n >> k;
  
  FOR (i, 0, n) {
    cin >> a[i];
  }

  if (k >= a[n - 1]) {
    cout << 0 << ENDL;
    return;
  }
  
  int l = 1, r = a[0] + 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (eval(m) != -1) {
      r = m;
    } else {
      l = m + 1; 
    }
  }
  cout << eval(l) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;
  FOR (i, 0, t) {
    solve(t + 1);  
  }

  return 0;
}