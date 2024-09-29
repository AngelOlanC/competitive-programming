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

int N, K;
string S;

int mx[40][40][40*40];
int dp_mx(int i, int j, int k) {
  if (i == N) return 0;
  int &ans = mx[i][j][k];
  if (~ans) return ans;
  int useN = dp_mx(i + 1, j + 1, k);
  if (S[i] == 'N') return ans = useN;
  int useA = dp_mx(i + 1, j, k + j);
  if (S[i] == 'A') return ans = useA;
  int useC = k + dp_mx(i + 1, j, k);
  if (S[i] == 'C') return ans = useC;
  int useOther = dp_mx(i + 1, j, k);
  if (S[i] != '?') return ans = useOther;
  return ans = max({useN, useA, useC, useOther});
}

int mn[40][40][40*40];
int dp_mn(int i, int j, int k) {
  if (i == N) return 0;
  int &ans = mn[i][j][k];
  if (~ans) return ans;
  int useN = dp_mn(i + 1, j + 1, k);
  if (S[i] == 'N') return ans = useN;
  int useA = dp_mn(i + 1, j, k + j);
  if (S[i] == 'A') return ans = useA;
  int useC = k + dp_mn(i + 1, j, k);
  if (S[i] == 'C') return ans = useC;
  int useOther = dp_mn(i + 1, j, k);
  if (S[i] != '?') return ans = useOther;
  return ans = min({useN, useA, useC, useOther});
}

int nxt[40];
unordered_map<int, bool> memo[40][40][40*40];
bool dp(int i, int n, int na, int nac) {
  if (i == N) return nac == K;
  if (nac + dp_mn(i, n, na) > K || nac + dp_mx(i, n, na) < K) return 0;
  if (memo[i][n][na].find(nac) != memo[i][n][na].end()) {return memo[i][n][na][nac];}
  bool &ans = memo[i][n][na][nac];
  bool useN = dp(nxt[i], n + 1, na, nac);
  if (S[i] == 'N') return ans = useN;
  bool useA = dp(nxt[i], n, na + n, nac);
  if (S[i] == 'A') return ans = useA;
  bool useC = dp(nxt[i], n, na, nac + na);
  if (S[i] == 'C') return ans = useC;
  bool useOther = dp(nxt[i], n, na, nac);
  if (S[i] != '?')  return ans = useOther;
  return ans = useN | useA | useC | useOther;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(mx, -1, sizeof mx);
  memset(mn, -1, sizeof mn);
  cin >> N >> K >> S;
  {
    int last = N;
    ROF (i, N, 0) {
      nxt[i] = last;
      if (S[i] == '?' || S[i] == 'N' || S[i] == 'A' || S[i] == 'C') last = i;
    }
  }
  if (!dp(0, 0, 0, 0)) {
    cout << -1 << ENDL;
    return 0;
  }
  {
    int n = 0, na = 0, nac = 0;
    FOR (i, 0, N) {
      if (S[i] != 'N' && S[i] != 'A' && S[i] != 'C' && S[i] != '?') continue;
      bool useN = dp(i + 1, n + 1, na, nac);
      if (S[i] == 'N' || (S[i] == '?' && useN)) {
        S[i] = 'N';
        n++;
        continue;
      }
      bool useA = dp(i + 1, n, na + n, nac);
      if (S[i] == 'A' || (S[i] == '?' && useA)) {
        S[i] = 'A';
        na += n;
        continue;
      }
      bool useC = dp(i + 1, n, na, nac + na);
      if (S[i] == 'C' || (S[i] == '?' && useC)) {
        S[i] = 'C';
        nac += na;
        continue;
      }
      S[i] = 'X';
    }
  }
  cout << S << ENDL;
}