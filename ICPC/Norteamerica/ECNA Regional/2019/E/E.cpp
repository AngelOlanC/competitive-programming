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

using i128 = ll;
struct Frac {
  i128 num, den;

  Frac() {}
  Frac(i128 num, i128 den) {
    i128 g = gcd(num, den);
    this->num = num / g;
    this->den = den / g;
  }

  Frac operator*(Frac f) const { return Frac(num * f.num , den * f.den); }
  Frac operator/(Frac f) const { return (*this) * Frac(f.den, f.num );  }
  Frac operator+(Frac f) const { return Frac(num * f.den + den * f.num , den * f.den); }
  Frac operator-(Frac f) const { return Frac(num * f.den - den * f.num , den * f.den); }
  bool operator<(Frac& other) const { return num * other.den < other.num  * den; }
  bool operator==(Frac& other) const { return num == other.num  && den == other.den; }
  bool operator!=(Frac& other) const { return !(*this == other); }
};

const int maxm = 33 + 5, maxn = 12 + 5;

int m, n, p;
int vis[maxm][maxn];
Frac dp[maxm][maxn];

Frac solve(int i, int j) {
  if (j == 0) {
    return i == p ? Frac(1, 1) : Frac(0, 1);
  }

  if (i == p) {
    return Frac(0, 1);
  }

  if (vis[i][j]) {
    return dp[i][j];
  }

  vis[i][j] = 1;
  Frac &ans = dp[i][j] = Frac(0, 1);
  if (j) {
    Frac eliminar = Frac(2 * j, m - i) * solve(i + 1, j - 1);
    ans = ans + eliminar;
  }
  Frac no_eliminar = Frac(m - i - 2 * j, m - i) * solve(i + 1, j);
  ans = ans + no_eliminar;
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> m >> n >> p;

  Frac ans = solve(0, n);

  cout << ans.num  << '/' << ans.den << ENDL;

  return 0;
}