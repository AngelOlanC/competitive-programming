#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach moy
using i64 = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  priority_queue<int> rows;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      sum += a[i][j];
    }
    rows.push(sum);
  }
  vector<i64> max_rows(k + 1);
  for (int i = 1; i <= k; ++i) {
    int top = rows.top();
    rows.pop();
    max_rows[i] = max_rows[i - 1] + top;
    rows.push(top - m * p);
  }
  priority_queue<int> cols;
  for (int j = 0; j < m; ++j) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i][j];
    }
    cols.push(sum);
  }
  vector<i64> max_cols(k + 1);
  for (int i = 1; i <= k; ++i) {
    int top = cols.top();
    cols.pop();
    max_cols[i] = max_cols[i - 1] + top;
    cols.push(top - n * p);
  }
  i64 ans = -1e18;
  for (int used_rows = 0; used_rows <= k; ++used_rows) {
    ans = max(ans, max_rows[used_rows] + max_cols[k - used_rows] - (i64)used_rows * (k - used_rows) * p);
  }
  cout << ans << '\n';
}