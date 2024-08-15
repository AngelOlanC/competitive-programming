#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

int main(int argc, char* argv[]) {
  assert(argc == 2);
  int subproblem = stoi(argv[1]);
  int n, m;
  long long k;
  if (subproblem == 1) {
    n = m = 3;
    k = 1;
  } else if (subproblem == 2) {
    do {
      n = random(1, 4), m = random(1, 4);
    } while (n * m > 12);
    k = random(1, 10);
  } else if (subproblem == 3) {
    n = random(700, 1000), m = random(700, 1000), k = random(1, 1e7);
  } else {
    n = random(700, 1000), m = random(700, 1000);
    int k1 = random(1, 1e9), k2 = random(1, 1e9);
    k = (long long)k1 * k2;
  }
  cout << n << ' ' << m << ' ' << k << '\n';
  cout << random(1, n) << ' ' << random(1, m) << '\n';
}