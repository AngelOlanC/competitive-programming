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
  static vector<C> rt(2, 1);
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
        C z = rt[j+k] * a[i+j+k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
}

vi conv(const vi &a, const vi &b) {
  if (a.empty() || b.empty()) return {};
  vi res(SZ(a) + SZ(b) - 1);
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

  string s, t;
  cin >> s >> t;

  reverse(ALL(t));

  vector<vector<vi>> c(6, vector<vi>(6));
  FOR (i, 0, 6) {
    FOR (j, 0, 6) {
      vi a(SZ(s)), b(SZ(t));
      FOR (k, 0, SZ(s)) {
        a[k] = s[k] - 'a' == i;
      }
      FOR (k, 0, SZ(t)) {
        b[k] = t[k] - 'a' == j;
      }
      c[i][j] = conv(a, b);
    }
  }

  FOR (i, SZ(t) - 1, SZ(s)) {
    vector<vi> nice(6, vi(6));
    int ans = 0;
    FOR (j, 0, 6) FOR (k, 0, 6) if (c[j][k][i]) nice[j][k] = 1;
    vi active(6);
    FOR (j, 0, 6) FOR (k, 0, 6) if (nice[j][k] || nice[k][j]) {
      active[j] = 1;
      ans++;
      break;
    }
    vi vis(6);
    queue<int> q;
    FOR (j, 0, 6) if (active[j] && !vis[j]) {
      ans--;
      q.push(j);
      vis[j] = 1;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        FOR (v, 0, 6) if ((nice[u][v] || nice[v][u]) && !vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
    cout << ans << " \n"[i == SZ(s) - 1];
  }

  return 0;
}