#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

vector<int> decompose(i64 x) {
  vector<int> ret;
  while (x) {
    ret.push_back(int(x % 10));
    x /= 10;
  }
  return ret;
}

i64 dp(int i, int last, bool less, bool leadingZeroes, vector<vector<i64>>& memo, vector<int>& x) {
  if (i == -1) {
    return 1;
  }
  i64 &ans = memo[last][i];
  if (less && !leadingZeroes && ans != -1) {
    return ans;
  }
  i64 ret = 0;
  int mx = less ? 9 : x[i];
  for (int d = 0; d <= mx; ++d) {
    if (d != last || (!d && leadingZeroes)) {
      ret += dp(i - 1, d, less || d < x[i], leadingZeroes && !d, memo, x);
    }
  }
  return less && !leadingZeroes ? ans = ret : ret;
}

i64 solve(i64 x) {
  if (x <= 0) {
    return !x;
  }
  vector<int> dx = decompose(x);
  vector<vector<i64>> memo(10, vector<i64>((int)dx.size(), -1));
  return dp((int)dx.size() - 1, 0, false, true, memo, dx);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  i64 a, b;
  cin >> a >> b;
  
  cout << solve(b) - solve(a - 1) << '\n';

  return 0;
}