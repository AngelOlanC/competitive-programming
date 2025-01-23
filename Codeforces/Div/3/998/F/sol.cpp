#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 998244353;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

inline int mul(int x, int y) {
  return int((long long)x * y % MOD);
}

int be(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) {
      ret = mul(ret, x);
    }
    x = mul(x, x);
    k >>= 1;
  }
  return ret;
}

int inv(int x) {
  return be(x, MOD - 2);
}

int comb(int n, int k) {
  if (n < k) {
    return 0;
  }
  int num = 1, den = 1;
  for (int i = 0; i < k; ++i) {
    num = mul(num, n - i);
  }
  for (int i = 1; i <= k; ++i) {
    den = mul(den, i);
  }
  // cout << "num=" << num << ", den=" << den << ", comb[" << n << "][" << k << "]=" << mul(num, inv(den)) << '\n';
  return mul(num, inv(den));
}

void solve(vector<vector<int>>& div) {
  int k, n;
  cin >> k >> n;

  vector<vector<int>> dp(17, vector<int>(k + 1));
  fill(dp[0].begin(), dp[0].end(), 1);
  for (int i = 1; i < 17; ++i) {
    for (int j = 1; j <= k; ++j) {
      for (int d : div[j]) {
        dp[i][j] = add(dp[i][j], dp[i - 1][d]);
      }
    }
  }

  // for (int i = 1; i <= k; ++i) {
  //   cout << dp[1][i] << ' ';
  // }
  // cout << '\n';

  cout << n << ' ';
  for (int x = 2; x <= k; ++x) {
    int ans = 0;
    for (int i = 0; i < 17; ++i) {
      ans = add(ans, mul(dp[i][x], comb(n + 1, i + 2)));
    }
    cout << ans << " \n"[x == k];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vector<int>> div(1e5 + 1);
  for (int i = 2; i < (int)div.size(); ++i) {
    for (int j = 2 * i; j < (int)div.size(); j += i) {
      div[j].push_back(i);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    solve(div);
  }

  return 0;
}