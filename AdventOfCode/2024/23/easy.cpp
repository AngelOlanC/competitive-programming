#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int g[26][26][26][26];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  while (cin >> s) { 
    g[s[0] - 'a'][s[1] - 'a'][s[3] - 'a'][s[4] - 'a'] = true;
    g[s[3] - 'a'][s[4] - 'a'][s[0] - 'a'][s[1] - 'a'] = true;
  }

  int sing = 0, doub = 0, trip = 0, i = 't' - 'a';
  for (int j = 0; j < 26; ++j){ 
    for (int k = 0; k < 26; ++k) {
      for (int l = 0; l < 26; ++l) {
        if ((k == i && l == j) || !g[i][j][k][l]) {
          continue;
        }
        for (int m = 0; m < 26; ++m) {
          for (int n = 0; n < 26; ++n) {
            if ((m == i && n == j) || (m == k && n == l) || !g[i][j][m][n] || !g[k][l][m][n]) {
              continue;
            }
            if (k == i && m == i) {
              ++trip;
            } else if (k == i || m == i) {
              ++doub;
            } else {
              ++sing;
            }
          }
        }
      }
    }
  }
  cout << (trip / 3 + doub / 2 + sing) / 2 << '\n';

  return 0;
}