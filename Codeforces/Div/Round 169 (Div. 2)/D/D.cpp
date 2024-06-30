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

ll l, r;
ll dp[64][2][2][2][2];

ll solve(int i, int xmr, int xml, int ymr, int yml) {
  if (i == -1) {
    return 0;
  }
  
  ll &ans = dp[i][xmr][xml][ymr][yml];
  if (~ans) {
    return ans;
  }
  
  ans = solve(i - 1, xmr, xml, ymr, yml);

  // maximizar ans
  if (xmr) {
    if (xml) {
      if (ymr) {
        if (yml) {
          return ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, ymr, yml));
        }
        if ((l >> i) & 1) {
          return ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, ymr, yml));
        }
        return ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, ymr, 1));
      }
      if (yml) {
        if ((r >> i) & 1) {
          return ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, 1, yml));
        }
        return ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, ymr, yml));
      }
      if ((r >> i) & 1) {
        ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, 1, yml));
      } else {
        ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, ymr, yml));
      }
      if ((l >> i) & 1) {
        ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, ymr, yml));
      } else {
        ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, ymr, 1));
      }
      return ans;
    }
    if ((l >> i) & 1) {
      ans = max(ans, (1LL << i) + solve(i - 1, xmr, xml, ymr, yml));
    } else {
      
    }
    if (ymr) {
      if (yml) {
        return ans;
      }

      return ans;
    }
    return ans;
  }
  
  if (xml) {
    if (ymr) {
      if (yml) {
        return ans;
      }

      return ans;
    }
    return ans;
  }
  if (ymr) {
    if (yml) {
      return ans;
    }

    return ans;
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> l >> r;

  cout << solve(64, 0, 0, 0, 0) << ENDL;

  return 0;
}