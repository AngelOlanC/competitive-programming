#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  constexpr int N = 20;

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  vector<int> sub(1 << N), sup(1 << N);
  for (int x : a) {
    ++sub[x];
    ++sup[x];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < (1 << N); ++j) {
      if ((j >> i) & 1) {
        sub[j] += sub[j ^ (1 << i)];
      } else {
        sup[j] += sup[j ^ (1 << i)];
      }
    }
  }

  int mx = (1 << N) - 1;
  for (int x : a) {
    cout << sub[x] << ' ' << sup[x] << ' ' << n - sub[mx ^ x] << '\n';
  }
}