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
const int N = 2e5 + 5;
 
int par[N+1], sz[N+1];
void makeset(){
    for(int i=0;i<=N;i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int find(int v){
    if(v == par[v]) return v;
    return par[v] = find(par[v]);
}
int Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return 1;
}
 
int n, m, ok[N], res[N];
struct edge{
    int u, v, w, id;
};
edge a[N];
 
int cmp(edge a, edge b){
    return a.w < b.w;
}
 
int st[N][20], h[N], mx[N][20];
vector<ii> adj[N];
 
void dfs(int u, int p=-1){
    // cout << u << " ";
    for(auto [v, w]: adj[u]){
        if(v == p) continue;
        h[v] = h[u] + 1;
        dfs(v, u);
        st[v][0] = u;
        mx[v][0] = w;
    }
}
 
void init(){
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(st[i][j-1]){
                st[i][j] = st[st[i][j-1]][j-1];
                mx[i][j] = max(mx[i][j-1], mx[st[i][j-1]][j-1]);
            }
        }
    }
}
 
int get(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    int k = log2(h[u]);
 
    int ans = -1e9;
 
    Fod(i,k,0){
        if(h[u] - (1 << i) >= h[v]){
            ans = max(ans, mx[u][i]);
            u = st[u][i];
        }
    }
 
    if(u == v) return ans;
    Fod(i,k,0){
        if(st[u][i] && st[u][i] != st[v][i]){
            ans = max(ans, mx[u][i]);
            ans = max(ans, mx[v][i]);
            u = st[u][i];
            v = st[v][i];
        }
    }
 
    ans = max(ans, max(mx[u][0], mx[v][0]));
    return ans;
}
 
void solve(){
    makeset();
    cin >> n >> m;
    For(i,1,m){
        cin >> a[i].u >> a[i].v >> a[i].w;
        a[i].id = i;
    }
    sort(a + 1, a + m + 1, cmp);
 
    int mst = 0;
    for(int i=1;i<=m;i++){
        if(Union(a[i].u, a[i].v)){
            mst += a[i].w;
            adj[a[i].u].pb({a[i].v, a[i].w});
            adj[a[i].v].pb({a[i].u, a[i].w});
            ok[i] = 1;
        }
    }
    // cout << mst << "$\n";
    
    dfs(1, -1);
    init();
 
    For(i,1,m){
        if(ok[i]){
            res[a[i].id] = mst;
        }
        else{
            int tmp = get(a[i].u, a[i].v);
            // cout << a[i].u << ' ' << a[i].v << ' ' << tmp << "\n";
            res[a[i].id] = mst - tmp + a[i].w;
        }
    }
 
    For(i,1,m) cout << res[i] << "\n";
 
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