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
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto &x : a) {
      cin >> x;
    }
    for (auto &x : b) {
      cin >> x;
    }

    vi suf_a(n + 1, 0), suf_b(n + 1, 0);
    ROF (i, n, 0) {
      suf_a[i] = suf_a[i + 1] + (a[i] == 1 && b[i] <= 0);
      suf_b[i] = suf_b[i + 1] + (b[i] == 1 && a[i] <= 0);
    }

    int s1 = 0, s2 = 0;
    FOR (i, 0, n) {
      if (max(a[i], b[i]) == 0) {
        continue;
      }
      if (a[i] == -1 && b[i] == -1) {
        if (s1 + suf_a[i] < s2 + suf_b[i]) {
          s2--;
        } else {
          s1--;
        }
        continue;
      }
      if (a[i] <= 0) {
        s2++;
        continue;
      } 
      if (b[i] <= 0) {
        s1++;
        continue;
      }
      if (s1 + suf_a[i] < s2 + suf_b[i]) {
        s1++;
      } else {
        s2++;
      }
    }
    cout << min(s1, s2) << ENDL;
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