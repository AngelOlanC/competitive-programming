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

int output(int alice) {
  cout << (alice ? "Alicius" : "Bobius") << ENDL;
  exit(0);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n];
  FOR (i, 0, n) {
    cin >> a[i];
  }
  sort(a, a + n);

  int alice = 1, carry = 0;
  FOR (i, 0, n) {
    a[i] -= carry;
    if (!a[i]) {
      continue;
    }
    if (a[i] != 1) {
      output(alice);
    }
    carry += a[i];
    alice = !alice;
  }
  output(!alice);

  return 0;
}