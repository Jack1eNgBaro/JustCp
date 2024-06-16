 
/**
TO MY NOTION:
 
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
 
int n;
ii a[N];
vector<int> adj[N];
 
int dp[N][2];
void dfs(int u, int p){
    dp[u][0] = dp[u][1] = 0;
    for(int v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
 
        int opt1 = abs(a[u].fi - a[v].fi) + dp[v][0];
        int opt2 = abs(a[u].fi - a[v].se) + dp[v][1];
 
        int opt3 = abs(a[u].se - a[v].fi) + dp[v][0];
        int opt4 = abs(a[u].se - a[v].se) + dp[v][1];
 
 
        dp[u][0] += max(opt1, opt2);
        dp[u][1] += max(opt3, opt4);
    }
}
 
void solve(){
    cin >> n;
    For(i,0,n) adj[i].clear();
    For(i,1,n) cin >> a[i].fi >> a[i].se;
    For(i,2,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}
 
main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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