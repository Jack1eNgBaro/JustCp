/**
TO MY NOTION:  https://www.notion.so/T-i-6-11-327080694afb43e6a8ff63fe107fc2a2 
 
                                               ,----'   `-,
                     ___,-'~~~`---'~~~~`-----' ,-'        \,                      
             ___,---'          '        ,-~~~~~            :
        _,--'                 ,        ; ;       ) "   __   \,
   _,--'     ,                 ,'      :: "  ;  ` ,'  (\o\)  |
  / _,       `,                     ,  `; " ;    (     `~~ `'\
 ; /         ,`               ,     `    ~~~`. " ;   _     ,  `.
,'/          ` ,              `     ` ,  ,    \_/ ?   ;    )   `.
:;:            `                      `  ` ,     uu`--(___(    ~:
:::          , ,  ,            ,   ;     , `  ,-'      \~(  ~   :
||:          ` `  `         ,  ` ,'    ( ` _,-          \ \_   ~:
:|`.        , ,  ,          `_   ;       ) );            \__>   :
|:  : ;     ` `  ` ;  __,--~~ `-(         ( |              `.  ~|
:|  :         ` __,--'           :  ()    : :               |~  ;
|;  |  `     ,-'    ;             :  )(   | `.         /(   `. ~|
::  :   ~  _/;     ;               |   )  :  :        ; /    ;~ ;
{}  ;     /  :   ~ :               :      ; ,;        : `._,-  ,
{} /~    /   ;    ;                 : ,  |  `;         `.___,-'
  ;~    ;    ;  ~ `.                | `  )   ;
  :`    \    `;~   \                ;~   `-, `-.     VOI24
  `.__OOO;    `;_OOO;               )_____OO;_(O)
   ~~~~~~       ~~~~                ~~~~~~~~ ~~~~
   */
 
 
#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
#define MOD 1000000007
#define fi first
#define se second
#define ll long long
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
const int N = 1e6 + 1;
 
int n, sg[4*N];
vector<int> adj[N];
 
void update(int id, int l, int r, int pos, int val){
    if(pos < l || pos > r) return;
    if(l == r){
        sg[id] = val;
        return;
    }
    int m = l + r >> 1;
    update(id << 1, l, m, pos, val);
    update(id << 1 | 1, m + 1, r, pos, val);
    sg[id] = max(sg[id << 1], sg[id << 1 | 1]);
}
 
int find(int id, int l, int r, int k){
    if(l == r){
        if(sg[id] >= k) return l;
        return 0;
    }
    int m = l + r >> 1;
    if(sg[id << 1] >= k)
        return find(id << 1, l, m, k);
    if(sg[id << 1 | 1] >= 1)
        return find(id << 1 | 1, m + 1, r, k);
    return 0;        
}
 
int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return -1e9;
    if(l >= u && r <= v) return sg[id];
    int m = l + r >> 1;
    int g1 = get(id << 1, l, m, u, v);
    int g2 = get(id << 1 | 1, m + 1, r, u, v);
    return max(g1, g2);
}
 
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
 
int cnt[N], ans[N];
vector<int> mems[N];
 
void add(int u){
    update(1, 0, N, dep[u], cnt[dep[u]] + 1);
    ++cnt[dep[u]];
}
 
void del(int u){
    update(1, 0, N, dep[u], -1e9);
    --cnt[dep[u]];
}
 
void dfs(int u, int p, int keep){
    int mx = -1, bigchild = -1;
    for(int v: adj[u]){
        if(v == p) continue;
        if(maximize(mx, sz[v])){
            bigchild = v;
        }
    }
    for(int v: adj[u]){
        if(v == p || v == bigchild) continue;
        dfs(v, u, 0);
    }
    if(bigchild != -1){
        dfs(bigchild, u, 1);
        swap(mems[bigchild], mems[u]);
    }
 
    mems[u].pb(u);
    add(u);
 
    for(int v: adj[u]){
        if(v == p || v == bigchild) continue;
        for(int x: mems[v]){
            mems[u].pb(x);
            add(x);
        }
    }
 
    // cout << u << ":\n";
    // For(i,1,n) cout << cnt[i] << ' '; cout << "\n";
 
    // cout << u << ' ' << sg[1] << '\n';
    ans[u] = find(1, 0, N, sg[1]) - dep[u];
 
    if(keep == 0){
        for(int x: mems[u]) del(x);
    }
}
void solve(){
    cin >> n;
    For(i,2,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }   
    dfs_size(1, 0);
    For(i,0,N) update(1, 0, N, i, -1e9);
    dfs(1, 0, 1);
    For(i,1,n) cout << ans[i] << "\n";
}
 
int main(){
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