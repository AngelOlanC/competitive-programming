#include <bits/stdc++.h>

using namespace std;

bool good(vector<int> a) {
  if (!is_sorted(a.begin(), a.end())) {
    reverse(a.begin(), a.end());
    if (!is_sorted(a.begin(), a.end())) {
      return false;
    }
  }
  for (int i = 1; i < (int)a.size(); ++i) {
    if (a[i] == a[i - 1] || a[i] - a[i - 1] > 3) {
      return false;
    }
  }
  return true;
}

vector<int> line_to_vector(string line) {
  stringstream ss(line);
  vector<int> a;
  while (ss.good()) {
    int x;
    ss >> x;
    a.push_back(x);
  }
  return a;
}

int main() {
  string line;
  int ans = 0;
  while (getline(cin, line)) {
    vector<int> a = line_to_vector(line);
    if (good(a)) {
      ++ans;
      continue;
    }
    for (int i = 0; i < (int)a.size(); ++i) {
      vector<int> b(a.begin(), a.end());
      b.erase(b.begin() + i);
      if (good(b)) {
        ++ans;
        break;
      }
    }
  }
  cout << ans << '\n';
}