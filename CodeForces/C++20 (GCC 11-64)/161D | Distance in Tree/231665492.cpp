#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
#define MOD 1000000007
#define fi first
#define se second
#define int long long
#define ii pair<int,int>
#define Dennis "Top1Server"
#define Jack1e "DB bainao"
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
 
int n, k, ans;
vector<int> adj[N];
 
int sz[N], dep[N];
void dfs_size(int u, int p){    
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}
 
int cnt[N];
vector<int> mems[N];
 
void dfs(int u, int p, int keep){
    int mx = -1, bigchild = -1;
    for(int v: adj[u]){
        if(v == p) continue;
        if(maximize(mx, sz[v])){
            bigchild = v;
        }
    }
    for(int v: adj[u]) if(v != p && v != bigchild) dfs(v, u, 0);
    if(bigchild != -1){
        dfs(bigchild, u, 1);
        swap(mems[u], mems[bigchild]);
    }
 
    mems[u].pb(u);
    cnt[dep[u]]++;
    if(dep[u] + k <= n) ans += cnt[dep[u] + k];
 
    for(int v: adj[u]){
        if(v == p || v == bigchild) continue;
        for(int x: mems[v]){
            int dist = k - (dep[x] - dep[u]);
            if(dist >= 0 && dep[u] + dist <= n){
                ans += cnt[dep[u] + dist];
            }
        }
        for(int x: mems[v]){
            mems[u].pb(x);
            cnt[dep[x]]++;
        }
    }
    if(!keep) for(int x: mems[u]) --cnt[dep[x]];
}
 
void solve(){
    cin >> n >> k;
    For(i,2,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs_size(1, 1);
    dfs(1, 1, 1);
    cout << ans;
}
 
main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "tree-distance"
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