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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  unordered_map<string, bool> papa;
  unordered_map<string, string> sig;
  FOR (i, 1, n) {
    string s, t;
    cin >> s >> t;
    sig[t] = s;
    if (sig[s] == "") {
      sig[s] = "$";
    }
    papa[s] = 1;
    papa[t] = 0;
  }

  string raiz;
  for (auto &[s, c] : papa) {
    if (c == 0) {
      raiz = s;
      break;
    }
  }

  while (raiz != "$") {
    cout << raiz << ENDL;
    raiz = sig[raiz];
  }

  return 0;
}