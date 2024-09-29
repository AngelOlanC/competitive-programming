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

typedef double ld;
const ld PI = acos(-1.0L);
const ld one = 1;

typedef complex<ld> C;
typedef vector<ld> vd;

void fft(vector<C> &a) {
  int n = SZ(a), L = 31 - __builtin_clz(n);
  static vector<complex<ld>> R(2, 1);
  static vector<C> rt(2, 1);  // (^ 10% faster if double)
  for (static int k = 2; k < n; k *= 2) {
    R.resize(n);
    rt.resize(n);
    auto x = polar(one, PI / k);
    FOR(i, k, 2 * k)
    rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
  }
  vi rev(n);
  FOR(i, 0, n)
  rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  FOR(i, 0, n)
  if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) FOR(j, 0, k) {
        // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
        auto x = (ld *)&rt[j + k], y = (ld *)&a[i + j + k];         /// exclude-line
        C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);  /// exclude-line
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
}

typedef vector<ll> vl;

vl conv(const vl &a, const vl &b) {
  if (a.empty() || b.empty()) return {};
  vl res(SZ(a) + SZ(b) - 1);
  int L = 32 - __builtin_clz(SZ(res)), n = 1 << L;
  vector<C> in(n), out(n);
  copy(ALL(a), begin(in));
  FOR(i, 0, SZ(b))
  in[i].imag(b[i]);
  fft(in);
  for (C &x : in) x *= x;
  FOR(i, 0, n)
  out[i] = in[-i & (n - 1)] - conj(in[i]);
  fft(out);
  FOR(i, 0, SZ(res))
  res[i] = floor(imag(out[i]) / (4 * n) + 0.5);
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;

  reverse(ALL(t));

  vl a(n), b(m);
  FOR (i, 0, n) a[i] = s[i] == 'S';
  FOR (i, 0, m) b[i] = t[i] == 'R';
  vl cr = conv(a, b);

  FOR (i, 0, n) a[i] = s[i] == 'R';
  FOR (i, 0, m) b[i] = t[i] == 'P';
  vl cp = conv(a, b);

  FOR (i, 0, n) a[i] = s[i] == 'P';
  FOR (i, 0, m) b[i] = t[i] == 'S';
  vl cs = conv(a, b);

  ll ans = 0;
  FOR (i, m - 1, SZ(cr)) {
    ans = max(ans, cr[i] + cp[i] + cs[i]);
  }
  cout << ans << ENDL;

  return 0;
}