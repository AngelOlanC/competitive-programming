  #include <bits/stdc++.h>
  using namespace std;

  using ll = long long;
  using pi = pair<int, int>;
  using vi = vector<int>;

  #define pb push_back
  #define SZ(x) ((int)(x).size())
  #define ALL(x) begin(x), end(x)
  #define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
  #define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
  #define ENDL '\n'

  void solve(int test_case) {
    int n, r;
    cin >> n >> r;
    int ans = 0, res = 0;
    FOR (i, 0, n) {
      int x;
      cin >> x;
      int used = x / 2;
      r -= used;
      ans += used * 2;
      if (x & 1) res++;
    }
    int k = res / 2;
    if (res % 2) {
      ans++;
      --r;
    }
    ans += 2 * min(k, r - k);
    cout << ans << ENDL;
  }

  signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR (test_case, 0, tc) {
      solve(test_case + 1);
    }

    return 0;
  }