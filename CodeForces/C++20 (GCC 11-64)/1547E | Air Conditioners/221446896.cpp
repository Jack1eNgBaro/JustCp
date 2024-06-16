#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#define MOD 1000000007
#define fi first
#define se second
#define ll long long
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
#define bit(x, i) ((x >> i) & 1)
 
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
 
int n, k;
ii tv[N];
int a[N], sg[4*N][2];
 
void build(int id, int l, int r){
    if(l == r){
        if(a[l] > 1e9){
            sg[id][0] = sg[id][1] = 2e9;
            return;
        }else{
            sg[id][0] = a[l] - l;
            sg[id][1] = a[l] + l;
            return;
        }
    }
    int m = l + r >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    sg[id][0] = min(sg[id<<1][0], sg[id<<1|1][0]);
    sg[id][1] = min(sg[id<<1][1], sg[id<<1|1][1]);
}
 
int get(int id, int l, int r, int u, int v, int c){
    if(l > v || r < u) return 2e9;
    if(l >= u && r <= v){
        if(c == -1) return sg[id][0];
        if(c == +1) return sg[id][1];
    }
    int m = l + r >> 1;
    int g1 = get(id << 1, l, m, u, v, c);
    int g2 = get(id << 1 | 1, m + 1, r, u, v, c);
    return min(g1, g2);
}
 
void solve(){
    cin >> n >> k;
    For(i,1,k) cin >> tv[i].fi;
    For(i,1,k) cin >> tv[i].se;
 
    memset(a, 0x3f, sizeof(a));
    For(i,1,k){
        a[tv[i].fi] = tv[i].se;
    }
 
    build(1,1,n);
 
    For(i,1,n){
        int ans = 2e9;
        minimize(ans, a[i]);
        int L = get(1, 1, n, 1, i-1, -1);
        int R = get(1, 1, n, i+1, n, +1);
        minimize(ans, min(L+i, R-i));
        cout << ans << ' ';
    }
    cout << "\n";
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
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}