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
  int a[n], taken[n];
  FOR (i, 0, n) {
    cin >> a[i];
    taken[i] = 0;
  }

  for (int i = 1; i < n - 1; i += 2) {
    if (a[i] == 1) {
      i++;
    }
    taken[i] = 1;
  }

  vi p1, p2;
  FOR (i, 0, n) {
    if (taken[i]) {
      p1.pb(i);
    } else {
      p2.pb(i);
    }
  }
  sort(ALL(p1), [&](int i, int j) {
    return a[i] < a[j];
  });
  sort(ALL(p2), [&](int i, int j) {
    return a[i] < a[j];
  });
  int c = n;
  int b[n];
  for (auto &i : p1) {
    b[i] = c--;
  }
  for (auto &i : p2) {
    b[i] = c--;
  }
  FOR (i, 0, n) {
    cout << b[i] << ' ';
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