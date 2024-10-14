#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define pb push_back
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; --i)
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define ENDL '\n'

#define NEUT 0
struct STree {
    #define lson (k << 1) + 1, s, m
    #define rson (k << 1) + 2, m, e
    int n;
    vector<ll> st, lazy;
    STree(int n) : n(n), st((n << 2) + 5, NEUT), lazy((n << 2) + 5, NEUT) {}
    ll comb(ll x, ll y) { return x + y; }
    void push(int k, int s, int e) {
        if (!lazy[k]) return;
        st[k] += lazy[k] * (e - s);
        if (s + 1 != e) {
            lazy[(k << 1) + 1] += lazy[k];
            lazy[(k << 1) + 2] += lazy[k];
        }
        lazy[k] = 0;
    }
    void pull(int k) {
        st[k] = comb(st[(k << 1) + 1], st[(k << 1) + 2]);
    }
    ll query(int k, int s, int e, int a, int b) {
        push(k, s, e);
        if (a <= s && e <= b) return st[k];
        if (e <= a || b <= s) return NEUT;
        int m = (s + e) / 2;
        return comb(query(lson, a, b),
                    query(rson, a, b));
    }
    void add(int k, int s, int e, int a, int b, int v) {
        push(k, s, e);
        if (e <= a || s >= b) return;
        if (a <= s && e <= b) {
            lazy[k] += v;
            push(k, s, e);
            return;
        }
        int m = (s + e) / 2;
        add(lson, a,b,v);
        add(rson, a,b,v);
        pull(k);
    }
    void reset(int k, int s, int e, int i) {
        push(k, s, e);
        if (e <= i || s > i) return;
        if (s + 1 == e) {
            st[k] = 0;
            return;
        }
        int m = (s + e) >> 1;
        reset(lson, i), reset(rson, i);
        pull(k);
    }
    ll query(int a, int b) { return query(0, 0, n, a, b); }
    void add(int a, int b, int v) { add(0, 0, n, a, b, v); }
    void reset(int i) { reset(0, 0, n, i); }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<vi> ind(n);
    STree st(n);
    FOR (i, 0, n) {
        int x;
        cin >> x;
        --x;
        ind[x].pb(i);
        st.add(i, i + 1, n - i);
    }
    vector<vector<array<int, 3>>> Q(n);
    FOR (i, 0, q) {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r, --d;
        Q[d].pb({l, r, i});
    }
    set<int> topes;
    topes.insert(-1);
    topes.insert(n);
    vector<ll> ans(q);
    ROF (t, n, 0) {
        for (auto &[l, r, i] : Q[t]) {
            auto it = topes.lower_bound(r);
            int R = *it - 1, L = *(--it) + 1;
            ans[i] = st.query(l, r + 1);
            if (L <= r && R > r) ans[i] -= 1ll * (r - max(L, l) + 1) * (R - r);
        }
        for (auto &i : ind[t]) {
            auto it = topes.lower_bound(i);
            int R = *it - 1, L = *(--it) + 1;
            if (L != i) {
                st.add(L, i, -(R - i + 1));
            }
            st.reset(i);
            topes.insert(i);
        }
    }
    FOR (i, 0, q) {
        cout << ans[i] << ENDL;
    }

    return 0; 
}