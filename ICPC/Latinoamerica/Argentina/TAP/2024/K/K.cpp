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

const vi DI_T = {0, 0, 1, 2, 3, 4, 0}, DJ_T = {0, 1, 1, 1, 1, 1, 2};
const vi DI_A = {0, 1, 2, 3, 4, 0, 2, 0, 1, 2, 3, 4}, DJ_A = {0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2};
const vi DI_P = {0, 1, 2, 3, 4, 0, 2, 0, 1, 2}, DJ_P = {0, 0, 0, 0, 0, 1, 1, 2, 2, 2};

bool is_figure(vector<vi>& a, const vi& di, const vi& dj, int i, int j) {
  FOR (k, 0, SZ(di)) {
    int ii = i + di[k], jj = j + dj[k];
    if (ii < 0 || ii >= SZ(a) || jj < 0 || jj >= SZ(a[0]) || !a[ii][jj]) return false;
  }
  return SZ(di) == 7 || !a[i + 1][j + 1];
}

void clear(vector<vi>& a, const vi& di, const vi& dj, int i, int j) {
  FOR (k, 0, SZ(di)) a[i + di[k]][j + dj[k]] = 0;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vi> a(n, vi(m));
  FOR (i, 0, n) FOR(j, 0, m) {
    char c;
    cin >> c;
    a[i][j] = c == '#';
  }
  int T = 0, A = 0, P = 0;
  ROF (j, m, 0) FOR (i, 0, n){ 
    if (is_figure(a, DI_A, DJ_A, i, j)) {
      clear(a, DI_A, DJ_A, i, j);  
      A++;
      continue;
    }
    if (is_figure(a, DI_P, DJ_P, i, j)) {
      clear(a, DI_P, DJ_P, i, j);  
      P++;
      continue;
    }
    if (is_figure(a, DI_T, DJ_T, i, j)) {
      clear(a, DI_T, DJ_T, i, j);  
      T++;
    }
  }
  cout << T << ' ' << A << ' ' << P << ENDL;  
  return 0;
}