#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using ll = long long;
using ld = double;

constexpr int MOD = 998244353;

const ld PI = acos(-1.0L);
const ld one = 1;

typedef complex<ld> C;
typedef vector<ld> vd;

void fft(vector<C> &a) {
  int n = (int)a.size(), L = 31 - __builtin_clz(n);
  static vector<complex<ld>> R(2, 1);
  static vector<C> rt(2, 1);  // (^ 10% faster if double)
  for (static int k = 2; k < n; k *= 2) {
    R.resize(n);
    rt.resize(n);
    auto x = polar(one, PI / k);
    for (int i = k; i < 2 * k; ++i) {
      rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
  }
  vector<int> rev(n);
  for (int i = 0; i < n; ++i) {
    rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  }
  for (int i = 0; i < n; ++i) {
    if (i < rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; ++j) {
        auto x = (ld *)&rt[j + k], y = (ld *)&a[i + j + k];
        C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
    }
  }
}

using vl = vector<ll>;

vl circularConvMod(const vl &a, const vl &b, const int M, const int sz) {
  if (a.empty() || b.empty()) return {};
  vl res((int)a.size() + (int)b.size() - 1);
  int B = 32 - __builtin_clz((int)res.size()), n = 1 << B, cut = int(sqrt(M));
  vector<C> L(n), R(n), outs(n), outl(n);
  for (int i = 0; i < (int)a.size(); ++i) {
    L[i] = C((int)a[i] / cut, (int)a[i] % cut);
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    R[i] = C((int)b[i] / cut, (int)b[i] % cut);
  }
  fft(L), fft(R);
  for (int i = 0; i < n; ++i) {
    int j = -i & (n - 1);
    outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
    outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
  }
  fft(outl), fft(outs);
  for (int i = 0; i < (int)res.size(); ++i) {
    ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
    ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
    res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
  }
  if ((int)res.size() <= sz) {
    return res;
  }
  for (int i = sz; i < (int)res.size(); ++i) {
    res[i - sz] = (res[i - sz] + res[i]) % M;
  }
  res.resize(sz);
  return res;
}

inline int add(int a, int b, int m) {
  return a + b >= m ? a + b - m : a + b;
}

inline int sub(int a, int b, int m) {
  return a - b < 0 ? a - b + m : a - b;
}

inline int mul(int a, int b, int m) {
  return int((ll)a * b % m);
}

int be(int a, int b, int m) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a, m);
    }
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}

int generator(int p) {
  if (p == 2) {
    return 1;
  }

  vector<int> fact;
  int phi = p - 1,  n = phi;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    fact.push_back(n);
  }

  for (int res = 2; res <= p; ++res) {
    bool ok = true;
    for (int i = 0; i < (int)fact.size() && ok; ++i) {
      if (be(res, phi / fact[i], p) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      return res;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string k;
  int p, x;
  cin >> k >> p >> x;

  int root = generator(p);
  vector<int> lg(p), ilg(p);
  {
    int x = 1, id = 0;
    do {
      lg[x] = id;
      ilg[id] = x;
      ++id;
      x = mul(x, root, p);
    } while (x != 1);
  }

  // for (int i = 1; i < p; ++i) {
  //   cout << lg[i] << " \n"[i == p - 1];
  // }

  vector<vector<int>> comb(p, vector<int>(p));
  comb[0][0] = 1;
  for (int i = 1; i < p; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1], p);
    }
  }
  
  vl ways(p - 1);
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (comb[i][j]) {
        ++ways[lg[comb[i][j]]];
      }
    }
  }

  reverse(k.begin(), k.end());
  vl dp = { 1 };
  for (char c : k) {
    if (c == '1') {
      dp = circularConvMod(dp, ways, MOD, p - 1);
    }
    ways = circularConvMod(ways, ways, MOD, p - 1);
  }

  cout << dp[lg[x]] << '\n';

  return 0;
}