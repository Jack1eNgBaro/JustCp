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
 
vector<ii> adj[N];
int n, Q, s, n2, ls[3*N], rs[3*N];
int d[3*N];
 
ii build(int l, int r){
 if(l + 1 == r) return ii(l, l);
 int mid = l + r >> 1;
 auto [l1, l2] = build(l, mid);
 auto [r1, r2] = build(mid, r);
 
 int o1 = n2++, o2 = n2++;
 ls[o1] = l1; rs[o1] = r1;
 ls[o2] = l2; rs[o2] = r2;
 
 adj[o1].pb(ii(l1, 0));
 adj[o1].pb(ii(r1, 0));
 
 adj[l2].pb(ii(o2, 0));
 adj[r2].pb(ii(o2, 0));
 
 return ii(o1, o2);
}
 
void up1(int o, int l, int r, int ql, int qr, int st, int w){
 if(l > qr || r < ql) return;
 if(l >= ql && r <= qr){
  adj[st].pb(ii(o, w));
  return;
 }
 int mid = l + r >> 1;
 if(qr <= mid) up1(ls[o], l, mid, ql, qr, st, w);
 else if(mid <= ql) up1(rs[o], mid, r, ql, qr, st, w);
 else{
  up1(ls[o], l, mid, ql, mid, st, w);
  up1(rs[o], mid, r, mid, qr, st, w);
 }
}
 
void up2(int o, int l, int r, int ql, int qr, int st, int w){
 if(l > qr || r < ql) return;
 if(l >= ql && r <= qr){
  adj[o].pb(ii(st, w));
  return;
 }
 int mid = l + r >> 1;
 if(qr <= mid) up2(ls[o], l, mid, ql, qr, st, w);
 else if(ql >= mid) up2(rs[o], mid, r, ql, qr, st, w);
 else{
  up2(ls[o], l, mid, ql, mid, st, w);
  up2(rs[o], mid, r, mid, qr, st, w);
 }
}
 
void solve(){
    cin >> n >> Q >> s;
    n2 = n + 1;
    auto [root1, root2] = build(1, n + 1);
    while(Q--){
     int op; cin >> op;
     if(op == 1){
      int u, v, w; cin >> u >> v >> w;
      adj[u].pb(ii(v, w));
     }else if(op == 2){
      int u, l, r, w; cin >> u >> l >> r >> w;
      up1(root1, 1, n + 1, l, r + 1, u, w);
     }else if(op == 3){
      int u, l, r, w; cin >> u >> l >> r >> w;
      up2(root2, 1, n + 1, l, r + 1, u, w);
     }
    }
 
    memset(d, 0x3f, sizeof(d));
    int inf = d[0];
 
    priority_queue<ii, vector<ii>, greater<ii>> q;
    d[s] = 0;
    q.push(ii(d[s], s));
 
    while(q.size()){
     auto [dis, u] = q.top(); q.pop();
     if(dis != d[u]) continue;
     for(auto [v, w]: adj[u]){
      if(d[v] > d[u] + w){
       d[v] = d[u] + w;
       q.push(ii(d[v], v));
      }
     }
    }
    For(i,1,n){
     if(d[i] == inf) d[i] = -1;
     cout << d[i] <<" ";
    }
 
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