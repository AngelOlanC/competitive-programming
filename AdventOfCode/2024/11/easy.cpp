#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
vector<long long> blink(vector<long long> a) {
  long long n = a.size();
  vector<long long> b;
  for (long long x : a) {
    if (x == 0) {
      b.push_back(1);
      continue;
    }
    string xs = to_string(x);
    long long m = xs.size();
    if (m % 2 == 0) {
      b.push_back(stoll(xs.substr(0, m / 2)));
      b.push_back(stoll(xs.substr(m / 2)));
    } else {
      b.push_back(x * 2024);
    }
  }
  return b;
}
signed main() {
  vector<long long> a;
  long long x;
  while (cin >> x) {
    a.push_back(x);
  }
  for (long long i = 0; i < 75; ++i) {
    cout << i << '\n';
    a = blink(a);
  }
  cout << a.size() << '\n';
  return 0;
}