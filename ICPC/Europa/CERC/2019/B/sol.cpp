#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct SparseTable {
  bool mx;
  vector<vector<int>> jmp;

  SparseTable(vector<int>& V, bool mx) : mx(mx) {
    init(V);
  }

  void init(const vector<int>& V) {
    jmp.emplace_back(V);
    for (int pw = 1, k = 1; pw * 2 <= (int)V.size(); pw *= 2, ++k) {
      jmp.emplace_back((int)V.size()- pw * 2 + 1);
      for (int j = 0; j < (int)jmp[k].size(); ++j) {
        if (mx) {
          jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
        } else {
          jmp[k][j] = gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
      }
    }
  }
  int query(int l, int r) {
    ++r;
    int dep = 31 - __builtin_clz(r - l);
    if (mx) {
      return max(jmp[dep][l], jmp[dep][r - (1 << dep)]);
    }
    return gcd(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

constexpr int MOD = 1e9 + 7;

using i64 = long long;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

inline int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

pair<int, int> findMax(int l, int r, SparseTable& stMax) {
  int mx = stMax.query(l, r);
  int lo = l, hi = r;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (stMax.query(l, mid) < mx) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return {lo, mx};
}

int findLastLeft(int l, int x, int m, SparseTable& stGcd) {
  const int g = stGcd.query(x, m);
  int lo = l, hi = x;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (stGcd.query(mid, m) != g) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int findLastRight(int r, int x, int m, SparseTable& stGcd) {
  const int g = stGcd.query(m, x);
  int lo = x, hi = r;
  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if (stGcd.query(m, mid) != g) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  return lo;
}

int f(int l, int r, SparseTable& stMax, SparseTable& stGcd) {
  if (l > r) {
    return 0;
  }
  auto [m, mx] = findMax(l, r, stMax);
  vector<int> left, right;
  for (int i = m; i >= l; --i) {
    int j = findLastLeft(l, i, m, stGcd);
    left.push_back(j);
    i = j;
  }
  for (int i = m; i <= r; ++i) {
    int j = findLastRight(r, i, m, stGcd);
    right.push_back(j);
    i = j;
  }


  int ret = 0;
  for (int i = 0; i < (int)left.size(); ++i) {
    int li = left[i], ri = i ? left[i - 1] - 1 : m;
    for (int j = 0; j < (int)right.size(); ++j) {
      int lj = j ? right[j - 1] + 1 : m, rj = right[j];
      ret = add(ret, mul(mul(mul(ri - li + 1, rj - lj + 1), mx), gcd(stGcd.query(li, m), stGcd.query(m, rj))));
    }
  }
  ret = add(ret, add(f(l, m - 1, stMax, stGcd), f(m + 1, r, stMax, stGcd)));
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  SparseTable stMax(a, true), stGcd(a, false);
  cout << f(0, n - 1, stMax, stGcd) << '\n';

  return 0;
}