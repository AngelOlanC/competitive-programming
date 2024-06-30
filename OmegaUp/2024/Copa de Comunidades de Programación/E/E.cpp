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

#define N 10005

int a[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  while (cin >> n && n) {
    int xorr = 0;
    FOR (i, 0, n) {
      cin >> a[i];
      cout << (a[i] ^ xorr) << ' ';
      xorr = a[i];
    }
    cout << ENDL;
  }

  return 0;
}