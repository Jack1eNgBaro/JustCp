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
const int N = 5e5 + 5;
 
int oo, n, Q, a[N];
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
 
int res[N]; //KQ
vector<int> vec[N];
vector<ii> ask[N];
 
int d[N];   //d[i]: so luong mau co it nhat i nut mang mau day
int cnt[N]; //cnt[i]: so luong nut co mau i
 
void add(int u){
    ++cnt[a[u]];    ++d[cnt[a[u]]];
}
 
void del(int u){
    --d[cnt[a[u]]];  --cnt[a[u]];    
}
 
void dfs(int u, int p, int keep){
    int MX = -1, bigchild = -1;
    for(int v: adj[u]){
        if(v == p) continue;
        if(maximize(MX, sz[v])) bigchild = v;
    }
 
    for(int v: adj[u]){
        if(v == p || v == bigchild) continue;
        dfs(v, u, 0);
    }
    if(bigchild != -1){
        dfs(bigchild, u, 1);
        swap(vec[u], vec[bigchild]);
    }
    vec[u].pb(u); add(u);
    for(int v: adj[u]){
        if(v == p || v == bigchild) continue;
        for(int x: vec[v]){
            vec[u].pb(x); add(x);
        }
    }   
 
    for(int i=0;i<ask[u].size();i++){
        res[ask[u][i].se] = d[ask[u][i].fi];
    }    
 
    if(keep == 0) for(int x: vec[u]) del(x);
}
 
void solve(){
    // cin >> oo ;
    cin >> n;
    cin >> Q;
    For(i,1,n) cin >> a[i];
    For(i,2,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs_size(1, 0);
    // cin >> Q;
    For(i,1,Q){
        int u, k; cin >> u >> k;
        ask[u].pb({k, i});
    }
    dfs(1, 0, 1);
    For(i,1,Q) cout << res[i] << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "tcq"
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