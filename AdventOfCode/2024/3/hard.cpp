#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

string line;
int n;

bool match(int i, char c) {
  return i < n && line[i] == c;
};

int ans;
bool ok;

void mul(int i) {
  if (!ok || !match(i, 'm') || !match(i + 1, 'u') || !match(i + 2, 'l') || !match(i + 3, '(')) {
    return;
  }
  int x = 0, j = i + 4;
  while (j < n && isdigit(line[j])) {
    x *= 10;
    x += line[j] - '0';
    ++j;
  }
  if (!match(j, ',')) {
    return;
  }
  ++j;
  int y = 0;
  while (j < n && isdigit(line[j])) {
    y *= 10;
    y += line[j] - '0';
    ++j;
  }
  if (match(j, ')')) {
    ans += x * y;
  }
}

void doo(int i) {
  if (match(i, 'd') && match(i + 1, 'o') && match(i + 2, '(') && match(i + 3, ')')) {
    ok = true;
  }
}

void dont(int i) {
  if (match(i, 'd') && match(i + 1, 'o') && match(i + 2, 'n') && match(i + 3, '\'') && match(i + 4, 't') && match(i + 5, '(') && match(i + 6, ')')) {
    ok = false;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ans = 0;
  ok = true;
  while (cin >> line) {
    n = (int)line.size();
    for (int i = 0; i < n; ++i) {
      mul(i);
      doo(i);
      dont(i);
    }
  }
  cout << ans << '\n';
  return 0;
}