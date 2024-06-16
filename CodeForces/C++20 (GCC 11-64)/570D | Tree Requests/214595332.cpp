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
const int N = 5e5 + 5;
 
int n, q, sz[N], dep[N];
vector<int> adj[N];
char a[N];
 
void dfs_size(int u, int p=-1){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}
 
int cnt[N][26], cntf[N];
vector<int> vec[N];
vector<ii> ass[N];
int ans[N];
 
void update(int u, int x){
    cntf[dep[u]] -= cnt[dep[u]][a[u]-'a'];
    cnt[dep[u]][a[u]-'a'] ^= 1;
    cntf[dep[u]] += cnt[dep[u]][a[u]-'a'];
}
 
void dfs(int u, int p, int keep){
    int Max = 0, bigchild = -1;
    for(int v: adj[u]){
        if(v == p) continue;
        if(maximize(Max, sz[v])){
            bigchild = v;
        }
    }
    for(int v: adj[u]){
        if(v == p || v == bigchild) continue;
        dfs(v, u, 0);
    }
    if(bigchild != -1){
        dfs(bigchild, u, 1);
        swap(vec[u], vec[bigchild]);
    }
 
    vec[u].pb(u);
    update(u, 1);
 
    for(int v: adj[u]){
        if(v == p || v == bigchild) continue;
        for(int x: vec[v]){
            vec[u].pb(x);
            update(x, 1);
        }
    }
 
    for(auto it: ass[u]){
        ans[it.se] = cntf[it.fi] <= 1;
    }
 
    if(keep == 0){
        for(int v: vec[u]){
            update(v, -1);
        }
    }
}
 
void solve(){
    cin >> n >> q;
    For(i,2,n){
        int x; cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    dep[1] = 1;
    dfs_size(1, 0);
    For(i,1,n) cin >> a[i];
    For(id,1,q){
        int x, y; cin >> x >> y;
        ass[x].pb({y, id});
    }
    dfs(1, 0, 1);
    For(i,1,q){
        if(ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}
 
int main(){
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