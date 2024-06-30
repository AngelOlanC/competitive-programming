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

void solve(int t) {
  int n;
  cin >> n;
  int a[n];
  FOR (i, 0, n) {
    cin >> a[i];
  }

  int p[n];
  iota(p, p + n, 0);
  sort(p, p + n, [&](int i, int j) { return a[i] < a[j]; });

  if (a[p[0]] == a[p[n - 1]]) {
    cout << "NO" << ENDL;
    return;
  }

  cout << "YES" << ENDL;
  char color[n];
  FOR (i, 0, n) {
    color[p[i]] = (i == 1 ? 'B' : 'R');
  }
  FOR (i, 0, n) {
    cout << color[i];
  }
  cout << ENDL;
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