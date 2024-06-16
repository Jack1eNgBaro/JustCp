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
const int N = 2e5 + 5;
 
int n, Q;
vector<int> adj[N];
 
int st[N][21], dep[N];
int fin[N], fout[N], timer = 0;
 
int cc = -1, cl = -1;
void dfs(int u, int p=-1){
    fin[u] = ++timer;
    if(maximize(cc, dep[u])) cl = u;
    for(int v: adj[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        st[v][0] = u;
    }
    fout[u] = timer;
}
 
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int k = log2(dep[u]);
    Fod(i,k,0){
        if(dep[u] - (1<<i) >= dep[v]){
            u = st[u][i];
        }
    }
    if(u == v) return u;
    Fod(i,k,0){
        if(st[u][i] && st[u][i] != st[v][i]){
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}
 
struct node{
    int u; //lca trong cay con
    int min_timer = 0, mi = 0;
    int max_timer = 0, mx = 0;
 
    node(){
    }
    node(int x){
        u = x;
        min_timer = fin[x]; mi = x;
        max_timer = fin[x]; mx = x;
    }
 
    friend node merge(const node &a, const node &b){
        node ans;
        ans.u = lca(a.u, b.u);
        ans.min_timer = min(a.min_timer, b.min_timer);
        if(a.min_timer < b.min_timer) 
            ans.mi = a.mi;
        else 
            ans.mi = b.mi;
 
        ans.max_timer = max(a.max_timer, b.max_timer);
        if(a.max_timer > b.max_timer) 
            ans.mx = a.mx;
        else 
            ans.mx = b.mx;
 
        return ans;
    }
 
};
 
node sg[4*N];
void build(int id, int l, int r){
    if(l == r){
        sg[id] = node(l);
        return;
    }
    int m = l + r >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    sg[id] = merge(sg[id << 1], sg[id << 1 | 1]);
}
 
node get(int id, int l, int r, int u, int v){
    int m = l + r >> 1;
    if(l > v || r < u) return node(u);
    if(l >= u && r <= v) return sg[id];
    node g1 = get(id << 1, l, m, u, v);
    node g2 = get(id << 1 | 1, m + 1, r, u, v);
    return merge(g1, g2);
}
 
void solve(){
    cin >> n >> Q;
    For(i,2,n){
        int x; cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }    
    dfs(1, 0);
    For(j,1,21) For(i,1,n){
        if(st[i][j-1]) st[i][j] = st[st[i][j-1]][j-1];
    }
    build(1, 1, n);
 
    while(Q--){
        int l, r; cin >> l >> r;
 
        node t1, t2, t3;
        node mynode = get(1, 1, n, l, r);
 
        int ans = -1, kick = -1;
 
        int min_pos = mynode.mi;
        t1 = get(1, 1, n, l, min_pos-1);
        t2 = get(1, 1, n, min_pos+1, r);
        
        if(l <= min_pos-1 && min_pos+1 <= r){
            t3 = merge(t1, t2);    
        }else if(l <= min_pos-1){
            t3 = t1;
        }else if(min_pos+1<=r){
            t3 = t2;
        }
        
        if(maximize(ans, dep[t3.u])){
            kick = min_pos;
        }
 
        // cout << min_pos << ' ' << kick << ' ' << t3.u << " " << ans << "\n";
 
        int max_pos = mynode.mx;
        t1 = get(1, 1, n, l, max_pos-1);
        t2 = get(1, 1, n, max_pos+1, r);
        if(l <= max_pos-1 && max_pos+1 <= r){
            t3 = merge(t1, t2);    
        }else if(l <= max_pos-1){
            t3 = t1;
        }else if(max_pos+1<=r){
            t3 = t2;
        }
        if(maximize(ans, dep[t3.u])){
            kick = max_pos;
        }
 
        // cout << min_pos << ' ' << kick << ' ' << t3.u << " " << ans << "\n";
        cout << kick << ' ' << ans << "\n";
    }
 
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