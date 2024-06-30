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

void build(int pot, int i, int j, vector<vector<char>>& m) {
  if (pot == 1) {
    m[i][j] = '#'; 
    return;
  }
  int div = pot / 3;
  FOR (r, 0, 3) {
    FOR (c, 0, 3) {
      int ii = i + r * div, jj = j + c * div;
      if (r != 1 || c != 1) {
        build(div, ii, jj, m);
        continue;
      }
      FOR (a, 0, div) {
        FOR (b, 0, div) {
          m[ii + a][jj + b] = '.';
        }
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int pot = pow(3, n);
  vector<vector<char>> m(pot, vector<char>(pot));
  build(pot, 0, 0, m);

  FOR (i, 0, pot) {
    FOR (j, 0, pot) {
      cout << m[i][j];
    }
    cout << ENDL;
  } 

  return 0;
}