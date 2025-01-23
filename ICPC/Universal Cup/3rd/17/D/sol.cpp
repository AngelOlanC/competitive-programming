#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 998244353;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

inline int sub(int x, int y) {
  return x >= y ? x - y : x - y + MOD;
}

pair<int, int> f(int i, int top, vector<tuple<int, int, int, int>>& inst, vector<vector<pair<int, int>>>& dp, vector<vector<bool>>& inStack) {
  // cout << i + 1 << ' ' << top << '\n';
  if (inStack[i][top]) {
    // cout << "valio madres " << i << ' ' << top << '\n';
    cout << "-1\n";
    exit(0);
  }
  if (dp[i][top].first != -1) {
    return dp[i][top];
  }

  auto [a, x, b, y] = inst[i];

  // cout << a << ' ' << x + 1 << ' ' << b << ' ' << y + 1 << '\n';

  if (a == -1 && !top) {
    return dp[i][top] = {0, 1}; 
  }

  if (a == top) {
    // cout << "POPEA " << '\n';
    return dp[i][top] = {x, 1};
  }

  inStack[i][top] = true;
  auto [j, d] = f(y, b, inst, dp, inStack);
  auto [j2, d2] = f(j, top, inst, dp, inStack);
  inStack[i][top] = false;
  return dp[i][top] = {j2, add(1, add(d, d2))};
}

constexpr int maxn = 1024;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  
  {
    string aux;
    getline(cin, aux);
  }

  vector<tuple<int, int, int, int>> inst(n);
  for (int i = 0; i < n; ++i) {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string aux;

    int a = -1, x = 0, b, y;

    if (line[0] == 'P') {
      ss >> aux >> a >> aux >> x >> aux >> aux >> b >> aux >> y;
    } else {
      ss >> aux >> aux >> b >> aux >> y;
    }

    inst[i] = { a, x - 1, b, y - 1 };
  }

  vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(maxn + 1, make_pair(-1, -1)));
  vector<vector<bool>> inStack(n, vector<bool>(maxn + 1));

  cout << f(0, 0, inst, dp, inStack).second << '\n';

  return 0;
}