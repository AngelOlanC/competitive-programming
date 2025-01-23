#include <bits/stdc++.h>

using namespace std;

bool good(string line) {
  stringstream ss(line);
  int last, dir = -1;
  ss >> last;
  while (ss.good()) {
    int curr;
    ss >> curr;
    if (curr == last) {
      return false;
    }
    if (curr > last) {
      if (dir == 2 || curr - last > 3) {
        return false;
      }
      dir = 1;
      last = curr;
      continue;
    }
    if (dir == 1 || last - curr > 3) {
      return false;
    }
    dir = 2;
    last = curr;
  }
  return true;
}

int main() {
  string line;
  int ans = 0;
  while (getline(cin, line)) {
    ans += good(line);
  }
  cout << ans << '\n';
}