#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int x[101];
bool can[10000001];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  can[0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 10000000; j >= x[i]; --j) {
      can[j] |= can[j - x[i]];
    }
  }

  int cnt = 0;
  for (int i = 1; i <= 10000000; ++i) {
    cnt += can[i];
  }

  cout << cnt << '\n';
  for (int i = 1; i <= 10000000; ++i) {
    if (can[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';

  return 0;
}