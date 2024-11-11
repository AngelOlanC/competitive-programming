#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

struct myhash {
  vector<int> pot_b;
  int m, s, h;
  myhash(int k, int m, int b) : pot_b(k + 1), m(m), s(0), h(0) {
    pot_b[0] = 1;
    for (int i = 1; i <= k; ++i) {
      pot_b[i] = (i64)pot_b[i - 1] * b % m;
      s += pot_b[i];
      if (s >= m) {
        s -= m;
      }
    }
  }
  void add(int p) {
    h += pot_b[p];
    if (h >= m) {
      h -= m;
    }
  }
  void reset() {
    h -= s;
    if (h < 0) {
      h += m;
    } 
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<myhash> h = {myhash(k, 1e9 + 7, 1000003), myhash(k, 1e9 + 9, 1000033)};

  map<pair<int, int>, int> first;
  first[{0, 0}] = -1;
  vector<int> cnt(k + 1), need(n + 1, k);
  int ans = 0, id = 1;
  for (int i = 0; i < n; ++i) {
    h[0].add(a[i]);
    h[1].add(a[i]);
    ++cnt[a[i]];
    --need[cnt[a[i]]];
    if (!need[id]) {
      h[0].reset();
      h[1].reset();
      ++id;
    }

    pair<int, int> hp = {h[0].h, h[1].h};
    if (first.find(hp) != first.end()) {
      ans = max(ans, i - first[hp]);
    } else {
      first[hp] = i;
    }
  }
  cout << ans << '\n';

  return 0;
}