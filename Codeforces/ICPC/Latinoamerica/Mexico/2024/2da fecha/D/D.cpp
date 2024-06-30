#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define ALL(x) (x.begin(), x.end())
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i=(int)a; i<(int)b; i++)
#define ROF(i,a,b) for(int i=(int)a - 1; i>=(int)b; i++)
#define ENDL '\n'

constexpr ll MOD = 1e9+7;

ll dp[805][9 * 805][2];
ll comb_p[25], comb_np[25];

ll solve(int n,int diff,int primero){
    if(n == 0) return !diff;

    ll &ans = dp[n][diff][primero];
    if(ans != -1) return ans;

    ans = 0;
    FOR (i, 0, 20) {
        ll prod = primero ? comb_p[i] : comb_np[i];
        ans = (ans + prod * solve(n - 1, abs(diff + i - 10), 0) % MOD) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof dp);

    FOR (i, 1, 10) {
        FOR (j, 1, 10) if (i != j) {
            comb_p[i - j + 10]++;
        }
    }

    FOR (i, 0, 10) {
        FOR (j, 0, 10) if (i != j) {
            comb_np[i - j + 10]++;
        }
    }

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout << solve(n, 0, 1) << ENDL;
    }
}
