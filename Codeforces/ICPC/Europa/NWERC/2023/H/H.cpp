#include <bits/stdc++.h>
using namespace std;
// BRO... CSM

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __

    int n;
    cin >> n;
    vi a(n);
    int cnt1 = 0,cnt2 =0;
    int mn = 3e8;
    FOR(i,0,n){
        cin >> a[i];
        if(a[i] == 1) cnt1++;
        else if(a[i] == 2) cnt2++;
        else mn = min(mn,a[i]);
    }
    sort(ALL(a));
    string ans = "";
    if(cnt2>=cnt1){
        FOR(i,0,cnt1){
            ans+="*(1+2)";
        }
        cnt2 -= cnt1;
        cnt1 = 0;
    }else{
        FOR(i,0,cnt2){
          cnt1--;
          if (cnt1 != 1) {
            ans+="*(1+2)";
          } else {
            ans += "*(1+1+2)";
            cnt1--;
          }
        }
        cnt2 = 0;
    }

    while(cnt1>4){
        ans += "*(1+1+1)";
        cnt1-=3;
    }

    bool usado = 1;
    if (cnt1 == 3) {
      ans += "*(1+1+1)";
      cnt1-=3;
    } else if (cnt1 == 4) {
      ans += "*(1+1+1+1)";
    } else if (cnt1 == 2) {
      ans += "*(1+1)";
    } else if (cnt1 == 1) {
      if (cnt2) {
        ans += "*(1+2)";
        cnt2--;
      } else if (mn != 3e8) {
        usado = 0;
        ans += "*(1+" + to_string(mn) + ")";
      } else {
        if (ans.empty()) {
          cout << 1 << ENDL;
          return 0;
        }
        ans.erase(ans.begin());
        cout << ans << ENDL;
        return 0;
      }
    }
    while (cnt2--) {
      ans += "*2";
    }
    FOR(i,0,n){
      if(a[i] == 1 || a[i] == 2 || !usado) {
          if (a[i] == mn) {
            usado = 1;
          }
          continue;
      }
      ans += "*"+to_string(a[i]);
    }
    
    ans.erase(ans.begin());
    cout << ans << ENDL;


    return 0;
}