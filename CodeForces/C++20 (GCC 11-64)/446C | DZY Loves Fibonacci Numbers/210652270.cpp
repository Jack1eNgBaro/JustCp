#include<bits/stdc++.h>
#define MOD 1000000007
#define fi first
#define se second
#define int long long
#define ii pair<int,int>
#define Dennis ""
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define el cout << '\n'
#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Fod(i, a, b) for(int i = (a); i >= (b); i--)
 
using namespace std;
template <class X, class Y> bool minimize(X &a, Y b){
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b){
    if (a < b) return a = b, true;
    return false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {return l + rng() % (r - l + 1);}
 
const int N = 3e5 + 5;
const int mod = 1e9 + 9;
 
int fib[N];
int n, q, a[N], sg[4*N];
ii lz[4*N];
 
void build(int id, int l, int r){
    if(l == r){
        sg[id] = a[l];
        return;
    }
    int m = l+r>>1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    sg[id] = (sg[id << 1] + sg[id << 1 | 1]) % mod;
}
 
void add(int id, int l, int r, int A, int B){
    sg[id] += A*(fib[r-l+1] - 1) + A;
    sg[id] += B*(fib[r-l+2] - 1);
    sg[id] %= mod;
 
    lz[id].fi = (lz[id].fi + A) % mod;
    lz[id].se = (lz[id].se + B) % mod;
}
 
void push(int id, int l, int r){
    int m = l + r >> 1;
    add(id << 1, l, m, lz[id].fi, lz[id].se);
    add(id << 1 | 1, m + 1, r
        , (fib[m - l] * lz[id].fi + fib[m - l + 1] * lz[id].se)  % mod
        , (fib[m - l + 1] * lz[id].fi + fib[m - l + 2] * lz[id].se) % mod);
    lz[id] = {0, 0};
}
 
void update(int id, int l, int r, int u, int v){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        add(id, l, r, fib[l-u+1], fib[l-u+2]);
        return;
    }
    push(id, l, r);
    int m = l + r >> 1;
    update(id << 1, l, m, u, v);
    update(id << 1 | 1, m + 1, r, u, v);
    sg[id] = (sg[id << 1] + sg[id << 1 | 1]) % mod;
}
 
int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return sg[id];
    push(id, l, r);
    int m = l + r >> 1;
    int g1 = get(id << 1, l, m, u, v);
    int g2 = get(id << 1 | 1, m + 1, r, u, v);
    return (g1 + g2) % mod;
}
 
void solve(){
    fib[1] = fib[2] = 1;
    For(i,3,N-1) fib[i] = (fib[i-1] + fib[i-2]) % mod;
    
    cin >> n >> q;
    For(i,1,n) cin >> a[i];
    build(1, 1, n);
 
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r; cin >> l >> r;
            update(1, 1, n, l, r);
        }else{
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
 
}
 
main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int bla = uniform_int_distribution<int>(1, 100)(rng);
    #define TASK ""
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}