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

/*
 * Descripcion: Este algoritmo permite multiplicar dos polinomios de longitud n
 * Tiempo: O(n log n)
 */

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

vi convMod(const vi &a, const vi &b, const int &M) {
  if (a.empty() || b.empty()) return {};
  vi res(SZ(a) + SZ(b) - 1);
  int B = 32 - __builtin_clz(SZ(res)), n = 1 << B, cut = int(sqrt(M));
  vector<C> L(n), R(n), outs(n), outl(n);
  FOR(i, 0, SZ(a))
  L[i] = C((int)a[i] / cut, (int)a[i] % cut);
  FOR(i, 0, SZ(b))
  R[i] = C((int)b[i] / cut, (int)b[i] % cut);
  fft(L), fft(R);
  FOR(i, 0, n) {
    int j = -i & (n - 1);
    outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
    outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
  }
  fft(outl), fft(outs);
  FOR(i, 0, SZ(res)) {
    ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
    ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
    res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
  }
  return res;
}

constexpr int MOD = 1009;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  vi cnt(m, 0);
  FOR (i, 0, n) {
    int x;
    cin >> x;
    cnt[x - 1]++;
  }

  priority_queue<pair<int, vi>> pq;
  FOR (i, 0, m) if (cnt[i]) {
    int bound = min(cnt[i], k) + 1;
    vi a(k + 1);
    FOR (i, 0, bound) a[i] = 1; 
    a.resize(bound);
    pq.push({-bound, a});
  }

  while (SZ(pq) != 1) {
    vi a = pq.top().second;
    pq.pop();
    vi b = pq.top().second;
    pq.pop();
    vi c = convMod(a, b, MOD);
    if (SZ(c) > k + 1) c.resize(k + 1);
    pq.push({-SZ(c), c});
  }
  cout << pq.top().second.back() << ENDL;

  return 0;
}