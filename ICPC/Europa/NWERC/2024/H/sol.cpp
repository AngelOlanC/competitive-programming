#include <bits/stdc++.h>
using namespace std;

int ask(int c, int r) {
  cout << "? " << c << ' ' << r << endl;
  int x;
  cin >> x;
  return x;
}

void ans(int c, int r) {
  cout << "! " << c << ' ' << r << endl;
}

void solve(int x, int l) {
  int delta = l - (x % l);
  if (!delta) {
    ans(x, x);
    return;
  }
  int y = ask(delta, x);
  ans(x, y);
}

int main() {
  int n;
  cin >> n;

  int x = ask(n, 1), l = -1;
  vector<int> id(n + 1, -1);
  id[x] = 0;
  for (int i = 1; i < 500; ++i) {
    x = ask(1, x);
    if (id[x] != -1) {
      l = i;
      break;
    }
    id[x] = i;
  }

  if (l == -1) {
    l = 500;
    do {
      l += 500;
      x = ask(500, x);
    } while (id[x] == -1);
    l -= id[x] + 1;
  }

  solve(x, l);
}