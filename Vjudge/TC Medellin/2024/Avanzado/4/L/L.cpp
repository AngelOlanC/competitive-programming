#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string s1,s2;
  cin >> s1 >> s2;
  if(s1 == s2){
    cout << "YES" << ENDL;
    return 0;
  }

  string s11;
  if(SZ(s1)%2 || SZ(s2)%2){
    printf("YES");
    return 0;
  }
  s11 = s1.substr(0,SZ(s1)/2);
  string s12 = s1.substr(SZ(s1)/2);
  cout << s11 << ' ' << s12 << ENDL;

  return 0;
}