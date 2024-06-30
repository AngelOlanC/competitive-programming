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

  void solve(int testcase) {
    string s, t;
    cin >> s >> t;

    int ans = SZ(s) + SZ(t);
    FOR (i, 0, SZ(t)) {
      int ptr = i;
      FOR (j, 0, SZ(s)) {
        if (s[j] == t[ptr]) {
          ptr++;
        }
        if (ptr == SZ(t)) {
          break;
        }
      }
      ans = min(ans, SZ(s) + i + SZ(t) - ptr);
    }
    cout << ans << ENDL;
  }

  signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR (i, 0, tc) {
      solve(i + 1);  
    }

    return 0;
  }