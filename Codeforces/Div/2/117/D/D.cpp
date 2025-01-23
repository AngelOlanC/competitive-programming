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

const int MX = 3e5 + 2;  // Tamano maximo del string S

inline int add(int a, int b, const int &mod) { return a + b >= mod ? a + b - mod : a + b; }
inline int sbt(int a, int b, const int &mod) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b, const int &mod) { return 1ll * a * b % mod; }

const int X[] = {257, 359};
const int MOD[] = {(int)1e9 + 7, (int)1e9 + 9};
vector<int> xpow[2];

struct hashing {
  vector<int> h[2];

  hashing(string &s) {
    int n = s.size();
    for (int j = 0; j < 2; ++j) {
      h[j].resize(n + 1);
      for (int i = 1; i <= n; ++i) {
        h[j][i] = add(mul(h[j][i - 1], X[j], MOD[j]), s[i - 1], MOD[j]);
      }
    }
  }
  // Hash del substring en el rango [i, j)
  ll value(int l, int r) {
    int a = sbt(h[0][r], mul(h[0][l], xpow[0][r - l], MOD[0]), MOD[0]);
    int b = sbt(h[1][r], mul(h[1][l], xpow[1][r - l], MOD[1]), MOD[1]);
    return (ll(a) << 32) + b;
  }
};

// Llamar la funcion antes del hashing
void calc_xpow(int mxlen = MX) {
  for (int j = 0; j < 2; ++j) {
    xpow[j].resize(mxlen + 1, 1);
    for (int i = 1; i <= mxlen; ++i) {
      xpow[j][i] = mul(xpow[j][i - 1], X[j], MOD[j]);
    }
  }
}

#define N 100010

int rifa[2][N];
ll val[2][N];

bool f(string s, int idx, int k) {
  int n = SZ(s);
  hashing h(s);
  val[idx][k] = h.value(0, k);
  for (int i = k; i < n; i += k) {
    if (h.value(i, i + k) != val[idx][k]) {
      return false;
    }
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  calc_xpow();

  FOR (i, 0, 2) {
    string s;
    cin >> s;
    int n = SZ(s);
    FOR (j, 1, n + 1) {
      if (n % j != 0) {
        continue;
      }
      rifa[i][j] = f(s, i, j);
    }
  }

  int ans = 0;
  FOR (i, 1, N) {
    ans += rifa[0][i] && rifa[1][i] && val[0][i] == val[1][i];
  }
  cout << ans << ENDL;

  return 0;
}