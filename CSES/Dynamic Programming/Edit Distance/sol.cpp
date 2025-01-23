#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int prevDp[5001], currDp[5001];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s, t;
  cin >> s >> t;

  for (int j = 1; j <= (int)t.size(); ++j) {
    prevDp[j] = j;
  }

  for (int i = 1; i <= (int)s.size(); ++i) {
    currDp[0] = i;
    for (int j = 1; j <= (int)t.size(); ++j) {
      if (s[i - 1] == t[j - 1]) {
        currDp[j] = prevDp[j - 1];
      } else {
        currDp[j] = 1 + min({prevDp[j], currDp[j - 1], prevDp[j - 1]});
      }
    }
    for (int j = 0; j <= (int)t.size(); ++j) {
      prevDp[j] = currDp[j];
    }
  }
  cout << prevDp[(int)t.size()] << '\n';

  return 0;
}