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

#define N 1000010

int n;
int a[N];
int b[N];
int vis[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  FOR (i, 0, n) {
    cin >> a[i];
    vis[a[i]] = 1;
  }
  sort(a, a + n);

  memset(b, -1, sizeof b);

  FOR (i, 2, N) {
    if (!vis[i]) {
      continue;
    }
    for (int j = i; j < N; j += i) {
      b[j] = max(b[j], j + i - 1);
    }
  }

  int ans = 0, ptr = 0;
  FOR (i, 0, n) {
    while (b[ptr] < a[i]) {
      ptr++;
    }
    ans = max(ans, a[i] - ptr);
  }
  cout << ans << ENDL;

  return 0;
}