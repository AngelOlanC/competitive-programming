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

using T = long double;

const T PI = acos(-1.0), PI_HALF = PI / 2.0;

constexpr T EPS = 1e-9;

T eval(T lad, T rad, T ang) {
    if (abs(ang - PI_HALF) <= EPS) {
        return PI * rad * rad * lad;
    }

    T lb = lad * cos(ang);
    T la = lad * sin(ang);

    T areaG = (rad + lb) * (rad + lb);
    T areaP = rad * rad;

    T slope = la / -lb;

    T inter_y = slope * rad;

    T H = -inter_y + la;
    T h = -inter_y;

    T conoG = areaG * H;
    T conoP = areaP * h;

    return conoG - conoP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << setprecision(9) << fixed;

    while (n--) {
        int lad, rad;
        cin >> lad >> rad;

        T l = 0, r = PI_HALF;

        T la = lad*1.0,ra = rad*1.0;

        FOR (i, 0, 40) {
            T m1 = l + (r - l) / 3;
            T m2 = r - (r - l) / 3;
            T f1 = eval(la, ra, m1);
            T f2 = eval(la, ra, m2);
            if (f1 < f2) {
                l = m1;
            } else {
                r = m2;
            }
        }
        
        cout << PI - l << ENDL;
    }
}
