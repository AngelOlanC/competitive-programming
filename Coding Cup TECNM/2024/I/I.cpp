#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using edge = tuple<int, int, int>;

#define pb push_back
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; --i)
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define ENDL '\n'
constexpr int dx[4] = {1,-1,0,0}, dy[4] ={0,0,1,-1};
constexpr int INF = 3e8;
    int n, m, I, D;

bool isValid(int x,int y){
    return (x>=0 && x<n&&y>=0&&y<m);
}

signed main() {

    pi ini, fin;

    cin >> n >> m;
    cin >> ini.first >> ini.second;
    cin >> fin.first >> fin.second;
    cin >> I >> D;

    vector<vector<char>> mat(n, vector<char>(m));
    vector<pair<pi, pi>> limites;
    pi inicio, final;
    inicio = {0, 0};
    final = {0, 0};


    bool espacio = true;
    vector<vi> pos(n,vi(m,-1));
    set<int> espacios;

    string s;
    getline(cin,s);
    FOR (i, 0, n) {
        getline(cin,s);
        FOR (j, 0, m) {
            char c=s[j];
            mat[i][j] = c;
            
            if(c == ' ' && espacio){
                pos[i][j] = SZ(limites);
                
                continue;
            }
            if(c!=' ' && !espacio){
                pos[i][j] = SZ(limites);
                //cout << c << ENDL;
                continue;
            }
            if (c != ' ' && espacio) {
                final = {i, max(j - 1, 0)};
                espacios.insert(SZ(limites));
                limites.pb({inicio, final});

                inicio = {i, j};
                espacio = false;
                pos[i][j] = SZ(limites);
                continue;
            }
            if (c == ' ' && !espacio) {
                
                final = {i, max(j - 1, 0)};
                limites.pb({inicio, final});
                inicio = {i,j};
                espacio = true;
                pos[i][j] = SZ(limites);
                
            }
        }
        limites.pb({inicio, {i,m-1}});
    }

    priority_queue<tuple<int,int,int>> pq;
    pq.push({0,ini.first,ini.second});
    vector<vi> dist(n, vi(m,INF));
    dist[ini.first][ini.second] = 0;
    while (!pq.empty()) {
        auto [du,ux,uy] = pq.top();
        pq.pop();
        du*=-1;

        if(ux == fin.first && uy == fin.second) break;
        if(du > dist[ux][uy]) continue;

        FOR(k,0,4){
            int vx = ux+dx[k],vy = uy+dy[k];
            if(!isValid(vx,vy)){
                continue;
            }
            if(dist[vx][vy] > du+I){
                dist[vx][vy] = du+I;
                pq.push({-dist[vx][vy],vx,vy});
            }
        }
        //ESPACIOS
        if(espacios.count({pos[ux][uy]})){
            //a
            if(pos[ux][uy]){
                int vx = limites[pos[ux][uy]-1].first.first, vy = limites[pos[ux][uy]-1].first.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
                }
                vx = limites[pos[ux][uy]-1].second.first, vy = limites[pos[ux][uy]-1].second.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
                }
            }
            if(pos[ux][uy] != SZ(limites)-1){
                int vx = limites[pos[ux][uy]+1].first.first, vy = limites[pos[ux][uy]+1].first.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
                }
                vx = limites[pos[ux][uy]+1].second.first, vy = limites[pos[ux][uy]+1].second.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
                }
            }
            continue;
        }


        //a
        int idx = pos[ux][uy];
        if(limites[idx].first == make_pair(ux,uy)){
            if(idx>=3){
                int vx = limites[pos[ux][uy]-2].first.first, vy = limites[pos[ux][uy]-2].first.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
                }
            }
        }else{
            int vx = limites[pos[ux][uy]].first.first, vy = limites[pos[ux][uy]].first.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
            }
        }

        //s
        if(idx>=3){
                int vx = limites[pos[ux][uy]-2].second.first, vy = limites[pos[ux][uy]-2].second.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
                }
            }
        

        //D
        if(idx< SZ(limites)-2){
                int vx = limites[pos[ux][uy]+2].first.first, vy = limites[pos[ux][uy]+2].first.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
                }
            }

        //F

        if(limites[idx].second == make_pair(ux,uy)){
            if(idx<= SZ(limites)-3){
                int vx = limites[pos[ux][uy]+2].second.first, vy = limites[pos[ux][uy]+2].second.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
                }
            }
        }else{
            int vx = limites[pos[ux][uy]].second.first, vy = limites[pos[ux][uy]].second.second;
                if(dist[vx][vy] > du+I){
                    dist[vx][vy] = du+I;
                    pq.push({-dist[vx][vy],vx,vy});
            }
        }

       
    }

/*
    FOR(i,0,m){
        cout << pos[0][i] << " ";
    }
    cout << ENDL;
    FOR(i,0,m){
        cout << dist[0][i] << " ";
    }
*/
    cout << dist[fin.first][fin.second] << ENDL;

    return 0; 
}