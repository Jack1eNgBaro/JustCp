 
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
 
const int mod = 998244353;
const int N = 1005 + 5;
 
int n, a[N];
#define vi vector<int>
unordered_map<int,vi> mp;
 
int powmod(int a, int b, int c){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return ans;
}
 
int dp[N+1], gt[N+1];
int ckn(int k, int n){
    if(k > n) return 0;
 
    int ans = gt[n];
    int tmp = powmod((gt[k] * gt[n-k] % mod), mod - 2, mod);
    ans *= tmp; 
    ans = (ans % mod + mod) % mod;
    return ans;
}
 
int count(int x, int cur_pos, int bounder){
    if(bounder - cur_pos <= 0) return 0;
    int ans = ckn(x, bounder - cur_pos);
    return ans;
}
 
int cnt[N];
void solve(){
    gt[0] = 1;
    For(i,1,N) gt[i] = (gt[i-1] * i) % mod;
 
    cin >> n;
    For(i,1,n) cin >> a[i];
 
    dp[n+1] = 1;
    Fod(i,n,1){
        if(a[i] <= 0) dp[i] = 0;
        else{
            For(j,i+1,n){
                dp[i] += dp[j+1] * count(a[i], i, j);
                dp[i] %= mod;
            }
        }
    }
    int ans = 0;
    For(i,1,n){
        ans += dp[i];
        ans %= mod;
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