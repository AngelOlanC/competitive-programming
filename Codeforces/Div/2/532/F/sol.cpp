#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

#define isOn(mask, b) ((mask >> b) & 1)

struct XorBasis {
  vector<int> basis;

  XorBasis(int m) : basis(m) {}
  XorBasis(vector<int> b) : basis(b) {}

  void reset() {
    for (int& x : basis) {
      x = 0;
    }
  }

  XorBasis copy() {
    return XorBasis(basis);
  }

  void insert(int mask) {
    for (int i = (int)basis.size() - 1; i >= 0; --i) {
      if (!isOn(mask, i)) {
        continue;
      }
      if (!basis[i]) {
        basis[i] = mask;
        return;
      }
      mask ^= basis[i];
    }
  }

  int max_xor() {
    int ret = 0;
    for (int i = (int)basis.size() - 1; i >= 0; --i) {
      if (!isOn(ret, i) && basis[i]) {
        ret ^= basis[i];
      }
    }
    return ret;
  }
};

XorBasis merge(XorBasis& a, XorBasis& b) {
  XorBasis ret = a.copy();
  for (int mask : b.basis) {
    if (mask) {
      ret.insert(mask);
    }
  }
  return ret;
}

void f(int L, int R, vector<int>& ind, vector<int>& a, vector<pair<int, int>>& Q, vector<int>& ans, vector<XorBasis>& xbL, vector<XorBasis>& xbR) {
  if (L == R) {
    for (int i : ind) {
      ans[i] = a[L];
    }
    return;
  }

  int M = (L + R) >> 1;

  xbL[M].reset();
  xbL[M].insert(a[M]);
  for (int i = M - 1; i >= L; --i) {
    xbL[i] = xbL[i + 1].copy();
    xbL[i].insert(a[i]);
  }

  xbR[M + 1].reset();
  xbR[M + 1].insert(a[M + 1]);
  for (int i = M + 2; i <= R; ++i) {
    xbR[i] = xbR[i - 1].copy();
    xbR[i].insert(a[i]);
  }

  vector<int> indL, indR;
  for (int i : ind) {
    auto [l, r] = Q[i];
    if (r <= M) {
      indL.push_back(i);    
    } else if (l > M) {
      indR.push_back(i);
    } else {
      ans[i] = merge(xbL[l], xbR[r]).max_xor();
    }
  }
  
  f(L, M, indL, a, Q, ans, xbL, xbR);
  f(M + 1, R, indR, a, Q, ans, xbL, xbR);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x: a) {
    cin >> x;
  }

  int q;
  cin >> q;

  vector<pair<int, int>> Q(q);
  vector<int> ind(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    
    --l;
    --r;
    
    Q[i] = {l, r};
    ind[i] = i;
  }

  vector<XorBasis> xbL(n, XorBasis(20)), xbR(n, XorBasis(20));
  vector<int> ans(q);
  f(0, n - 1, ind, a, Q, ans, xbL, xbR);

  for (int x : ans) {
    cout << x << '\n';
  }

  return 0;
}