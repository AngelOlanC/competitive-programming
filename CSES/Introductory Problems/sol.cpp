#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  if (n % 4 && (n + 1) % 4) {
    cout << "NO\n";
    return 0;
  }

  i64 s = (i64)n * (n + 1) >> 2;

  vector<int> l, r;
  for (int i = n; i; --i) {
    if (i <= s) {
      l.push_back(i);
      s -= i;
    } else {
      r.push_back(i);
    }
  }

  cout << "YES\n";
  cout << (int)l.size() << '\n';
  for (int x : l) {
    cout << x << ' ';
  }
  cout << '\n';

  cout << (int)r.size() << '\n';
  for (int x : r) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}