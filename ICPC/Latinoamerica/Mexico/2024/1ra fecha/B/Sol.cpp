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

constexpr int MOD = 1e9 + 7;

template <typename T>
struct Matrix {
  using VVT = vector<vector<T>>;

  VVT M;
  int n, m;

  Matrix(VVT aux) : M(aux), n(M.size()), m(M[0].size()) {}

  Matrix operator*(Matrix& other) const {
    int k = other.M[0].size();
    VVT C(n, vector<T>(k, 0));
    FOR(i, 0, n)
    FOR(j, 0, k)
    FOR(l, 0, m)
    C[i][j] = (C[i][j] + 1ll * M[i][l] * other.M[l][j] % MOD) % MOD;
    return Matrix(C);
  }

  Matrix operator^(ll p) const {
    assert(p >= 0);
    Matrix ret(VVT(n, vector<T>(n))), B(*this);
    FOR(i, 0, n) {
      ret.M[i][i] = 1;
    }

    while (p) {
      if (p & 1)
        ret = ret * B;
      p >>= 1;
      B = B * B;
    }
    return ret;
  }

  void print() {
    // cout << "--------" << ENDL;
    // FOR (i, 0, n) {
    //   FOR (j, 0, m) {
    //     cout << M[i][j] << ' ';
    //   }
    //   cout << ENDL;
    // }
    // cout << "--------" << ENDL;
  }
};

#define N 20

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  vector<vi> m_vert(N, vi(1, 0));
  m_vert[0][0] = 1;
  m_vert[1][0] = 0;
  m_vert[2][0] = 0;
  m_vert[3][0] = 0;
  m_vert[4][0] = 0;
  m_vert[5][0] = 0;
  m_vert[6][0] = 3;
  m_vert[7][0] = 0;
  m_vert[8][0] = 0;
  m_vert[9][0] = 0;
  m_vert[10][0] = 3;
  m_vert[11][0] = 0;
  m_vert[12][0] = 9;
  m_vert[13][0] = 0;
  m_vert[14][0] = 3;
  m_vert[15][0] = 0;
  m_vert[16][0] = 18;
  m_vert[17][0] = 0;
  m_vert[18][0] = 30;
  m_vert[19][0] = 0;

  vector<vi> m_hor(N, vi(N, 0));
  FOR (i, 0, N - 1) {
    m_hor[i][i + 1] = 1;
  }
  m_hor[N - 1][N - 6] = m_hor[N - 1][N - 10] = m_hor[N - 1][N - 14] = m_hor[N - 1][N - 18] = 3; 

  Matrix<int> vert(m_vert), hor(m_hor);

  vert.print();
  hor.print();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
  
    if (n < N) {
      int ans = 0;
      FOR (i, 0, n + 1) {
        ans += m_vert[i][0];
      }
      cout << ans << ENDL;
      continue;
    }

    n -= N - 1;

    Matrix hor_exp = hor ^ n;
    hor_exp.print();
    Matrix ver_mul = hor_exp * vert;
    ver_mul.print();
    
    int ans = 0;
    FOR (i, 0, N) {
      ans = (ans + ver_mul.M[i][0]) % MOD;
    }
    cout << ans << ENDL;
  }

  return 0;
}
