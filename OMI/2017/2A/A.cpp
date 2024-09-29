#include <iostream>

using namespace std;

long long pairs(int n) {
  return (long long)n * (n - 1) / 2;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int d = n / m, r = n % m, mx = n - m + 1;
  cout << pairs(d) * (m - r) + pairs(m + 1) * r << ' ' << pairs(mx) << '\n';

  return 0;
}