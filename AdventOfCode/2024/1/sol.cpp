#include <iostream>
#include <algorithm>
#include <set>
#include <map>

int main() {
  std::map<int, int> left, right;
  int x, y;
  while (std::cin >> x >> y) {
    ++left[x];
    ++right[y];
  }
  int ans = 0;
  for (auto [x, c] : left ) {
    ans += x * c * right[x];
  }
  std::cout << ans << '\n';
}