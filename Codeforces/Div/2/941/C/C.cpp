#include<bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin(), (v).end()
#define mp make_pair


using namespace std;

void work(){
    int n; cin >> n;
    vector<long long int> piles(n, 0);

    for(int i = 0; i < n; i++) cin >> piles[i];

    sort(all(piles));

    vector<long long int> newPiles;
    newPiles.pb(piles[0]);
    for(int i = 1; i < n; i++){
        if(piles[i] != piles[i - 1]) newPiles.pb(piles[i]);
    }

    bool winner = (newPiles.size() % 2);
    for(int i = newPiles.size() - 3; i >= 0; i--){
        if((i) % 2 == winner) continue;

        if(newPiles[i] + 1 < newPiles[i + 1]){
            // cout << newPiles[i] + 1 << " < " << newPiles[i + 1] << endl;
            // if(winner) cout << "Alice" << endl;
            // else cout << "Bob" << endl;
            winner = !winner;
        }
    }

    if(winner) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long int tc; cin >> tc;

    while (tc--) work();

    return 0; 
}