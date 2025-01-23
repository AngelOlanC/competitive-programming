#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  constexpr int N = 22;
  
  int n;
  cin >> n;
  
  vector<int> a(n), sos(1 << N, -1);
  for (int& x : a) {
    cin >> x;
    sos[x] = x;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < (1 << N); ++j) {
      if (sos[j] == -1 && ((j >> i) & 1)) {
        sos[j] = sos[j ^ (1 << i)];
      }
    }
  }

  constexpr int MAX = (1 << N) - 1;
  for (int x : a) {
    cout << sos[MAX ^ x] << ' ';
  }
  cout << '\n';

  return 0;
}