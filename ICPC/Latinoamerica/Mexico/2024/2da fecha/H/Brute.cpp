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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;

  int L[n], R[n];
  L[0] = n - 1;
  FOR (i, 1, n) {
    L[i] = i - 1;
  }
  R[n - 1] = 0;
  FOR (i, 0, n - 1) {
    R[i] = i + 1;
  }

  vector<int> ans;
  int alive = n, a = 0, b = n - 1;
  while (alive > 2) {
    int r = x % alive;
    while (r--) {
      a = R[a];
    }
    int l = y % alive;
    while (l--) {
      b = L[b];
    }
    if (a == b) {
      ans.pb(a + 1);
      R[L[a]] = R[a];
      L[R[a]] = L[a];
      a = R[a];
      b = L[a];
      alive--;
      continue;
    }
    alive -= 2;
    if (R[a] == b) {
      R[L[a]] = R[b];
      L[R[b]] = L[a];
      a = R[b];
      b = L[a];
      continue;
    }
    if (L[a] == b) {
      R[L[b]] = R[a];
      L[R[a]] = L[b];
      a = R[a];
      b = L[b];
      continue;
    }
    R[L[a]] = R[a], L[R[a]] = L[a];
    R[L[b]] = R[b], L[R[b]] = L[b];
    a = R[a], b = L[b];
  }
  if (alive >= 1) {
    ans.pb(a + 1);
  }
  if (alive == 2) {
    ans.pb(R[a] + 1);
  }
  sort(ALL(ans));
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << ENDL;

  return 0;
}