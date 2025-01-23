#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> dp;
  for (int i = 0; i < n; ++i) {
    int j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    if (j == (int)dp.size()) {
      dp.push_back(a[i]);
    } else {
      dp[j] = a[i];
    }
  }
  cout << (int)dp.size() << '\n';

  return 0;
}