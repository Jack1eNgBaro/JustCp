#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
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
const int N = 505;
 
int n, id[N];
set<int> adj[N];
vector<ii> edges;
 
int xa[N][2], f[N];
void dfs(int u, int p=-1){
    // cout << u << " ";
    for(int v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
 
        maximize(f[u], f[v]);
        if(xa[v][0] + 1 > xa[u][0]){
            xa[u][1] = xa[u][0];
            xa[u][0] = xa[v][0] + 1;
        }else if(xa[v][0] + 1 > xa[u][1]){
            xa[u][1] = xa[v][0] + 1;
        }
    }
    maximize(f[u], xa[u][0] + xa[u][1]);    
}
 
void solve(){
    cin >> n;
    For(i,2,n){
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
 
        edges.pb(make_pair(x, y));
    }
 
    int ans = 0;
    for(auto [u, v]: edges){
        adj[u].erase(v);
        adj[v].erase(u);
 
        memset(f, 0, sizeof(f));
        memset(xa, 0, sizeof(xa));
 
        dfs(u);
        dfs(v);
 
        maximize(ans, f[u] * f[v]);
 
        adj[u].insert(v);
        adj[v].insert(u);
    }
    cout << ans;
}
 
main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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