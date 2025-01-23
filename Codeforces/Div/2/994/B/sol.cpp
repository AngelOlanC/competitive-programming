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
  int N;
  string S;
  cin >> N >> S;
  int p = 0, s = 0;
  for (char &c : S) {
    if (c == 'p') {
      ++p;
    } else if (c == 's') {
      if (p) {
        cout << "NO" << '\n';
        return;    
      }
      ++s;
    }
  }
  if (!p || !s) {
    cout << "YES" << '\n';
    return;
  }
  if (p > 1 && s > 1) {
    cout << "NO" << '\n';
    return;
  }
  if ((S[0] == 's' && S.back() == 'p') || (S[0] == 's' && s == 1) || (S.back() == 'p' && p == 1)) {
    cout << "YES" << '\n';
    return;
  }
  cout << "NO" << '\n';
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