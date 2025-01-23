#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  constexpr int N = 24;

  int n;
  cin >> n;
  
  vector<int> sos(1 << N);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int x = (1 << (s[0] - 'a')) | (1 << (s[1] - 'a')) | (1 << (s[2] - 'a'));
    ++sos[x];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < (1 << N); ++j) {
      if ((j >> i) & 1) {
        sos[j] += sos[j ^ (1 << i)];
      }
    }
  }

  int ans = 0;
  for (int x : sos) {
    ans ^= (n - x) * (n - x);
  }
  cout << ans << '\n';
}