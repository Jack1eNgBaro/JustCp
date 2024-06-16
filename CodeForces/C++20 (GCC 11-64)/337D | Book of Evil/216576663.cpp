#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
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
 
const int N = 1e6 + 5;
const int mi = -1e9;
 
int n, m, d, ok[N];
vector<int> adj[N];
int down[N], up[N];
int xa[N][3], cha[N];
 
void dfs1(int u, int p=-1){
    if(ok[u]) down[u] = 0;
    else down[u] = mi;
    xa[u][1] = mi;
    xa[u][2] = mi;
    for(int v: adj[u]){
        if(v == p) continue;
        cha[v] = u;
        dfs1(v, u);
        if(down[v] > xa[u][1]){
            xa[u][2] = xa[u][1];
            xa[u][1] = down[v];
        }else if(down[v] > xa[u][2]){
            xa[u][2] = down[v];
        }
        down[u] = max(down[u], xa[u][1] + 1);
    }
}
 
void dfs(int u, int p=-1){
    if(u == 1){
        if(ok[u]) up[u] = 0;
        else up[u] = mi;
    }else{
        int p = cha[u];
        up[u] = up[p] + 1;
        if(ok[u] && (up[u]<0)) up[u] = 0;
        if(xa[p][1] == down[u]){
            up[u] = max(up[u], xa[p][2]+2);
        }else{
            up[u] = max(up[u], xa[p][1]+2);
        }
    }
    for(int v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
    }
}
 
void solve(){
    cin >> n >> m >> d;
    int cnt = 0;
    For(i,1,m){
        int x; cin >> x;
        ok[x] = 1;
    }
    For(i,1,n-1){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
 
    dfs1(1);
    dfs(1);
 
    // For(i,1,n) cout << down[i] << ' '; cout << "\n";
    // For(i,1,n) cout << up[i] << ' '; cout << "\n";
 
    int ans = 0;
    For(i,1,n){
            if(down[i] <= d && up[i] <= d) ++ans;
    }
    cout << ans;
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