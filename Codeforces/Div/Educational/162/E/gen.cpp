#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n = 100000;
  
  cout << "1\n";
  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    cout << "1 ";
  }
  cout << '\n';
  for (int i = 1; i < n; ++i) {
    cout << i << ' ' << i + 1 << '\n';
  }

  return 0;
}