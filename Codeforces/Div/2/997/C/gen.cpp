#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void process(vector<int>& a) {
  // cout << "-\n";
  map<int, int> mp;
  for (int msk = (1 << ((int)a.size())) - 1; msk; --msk) {
    vector<int> ind;
    for (int i = 0; i < (int)a.size(); ++i) {
      if ((msk >> i) & 1) {
        ind.push_back(i);
      }
    }
    bool ok = true;
    for (int i = 0; i < (int)ind.size(); ++i) {
      if (a[ind[i]] != a[end(ind)[-i - 1]]) {
        ok = false;
      }
    }
    if (ok) {
      mp[(int)ind.size()]++;
    }
  }
  pair<int, int> p = {-1, -1};
  for (auto [x, cnt] : mp) {
    p = max(p, make_pair(x, cnt));
  }
  if (p.second > (int)a.size()) {
    cout << "FOUND " << p.first << ' ' << p.second << ' ' << (int)a.size() << '\n';
    for (int x : a) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
    exit(0);
  }
}

void go(int i, vector<int>& a) {
  if (i == (int)a.size()) {
    process(a);
    return;
  }
  for (int j = 0; j < (int)a.size(); ++j) {
    a[i] = j;
    go(i + 1, a);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<int> a(8);
  go(0, a);

  // vector<int> b = {1, 1, 2, 3, 1, 2};
  // process(b);

  return 0;
}