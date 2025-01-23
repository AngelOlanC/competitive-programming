#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y, const int mod) {
  return x + y < mod ? x + y : x + y - mod;
}

inline int sub(int x, int y, const int mod) {
  return x >= y ? x - y : x - y + mod;
}

inline int mul(int x, int y, const int mod) {
  return int((i64) x * y % mod);
}

void f(int L, int R, vector<int>& id, vector<pair<int, int>>& Q, vector<vector<int>>& dpl, vector<vector<int>>& dpr, vector<int>& a, vector<int>& ans, int m) {
  if (Q.empty()) {
    return;
  }
  if (L == R) {
    int add = !a[L];
    for (int i : id) {
      ans[i] = 1 + add;
    }
    return;
  }

  int M = (L + R) >> 1;

  vector<int> idL, idR;
  for (int i : id) {
    auto [l, r] = Q[i];
    if (r <= M) {
      idL.push_back(i);
    }
    if (l > M) {
      idR.push_back(i);
    }
  }

  f(L, M, idL, Q, dpl, dpr, a,  ans, m);
  f(M + 1, R, idR, Q, dpl, dpr, a, ans, m);

  for (int i = 0; i < m; ++i) {
    dpl[i][M] = dpr[i][M + 1] = 0;
  }

  ++dpl[a[M]][M];
  ++dpl[0][M];
  for (int i = M - 1; i >= L; --i) {
    for (int j = 0; j < m; ++j) {
      dpl[j][i] = add(dpl[j][i + 1], dpl[sub(j, a[i], m)][i + 1], MOD);
    }
  }

  ++dpr[a[M + 1]][M + 1];
  ++dpr[0][M + 1];
  for (int i = M + 2; i <= R; ++i) {
    for (int j = 0; j < m; ++j) {
      dpr[j][i] = add(dpr[j][i - 1], dpr[sub(j, a[i], m)][i - 1], MOD);
    }
  }

  for (int i : id) {
    auto [l, r] = Q[i];
    if (l > M || r <= M) {
      continue;
    }
    ans[i] = mul(dpl[0][l], dpr[0][r], MOD);
    for (int j = 1; j < m; ++j) {
      ans[i] = add(ans[i], mul(dpl[j][l], dpr[m - j][r], MOD), MOD);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
    x %= m;
  }

  int q;
  cin >> q;
  
  vector<pair<int, int>> Q(q);
  for (auto &[l, r] : Q) {
    cin >> l >> r;
    --l;
    --r;
  }

  vector<int> ans(q);
  vector<vector<int>> dpl(m, vector<int>(n)), dpr(m, vector<int>(n));
  vector<int> id(q);
  iota(id.begin(), id.end(), 0);
  f(0, n - 1, id, Q, dpl, dpr, a, ans, m);

  for (int x : ans) {
    cout << x << '\n';
  }

  return 0;
}