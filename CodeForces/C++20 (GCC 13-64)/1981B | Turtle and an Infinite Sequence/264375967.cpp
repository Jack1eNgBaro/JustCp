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
 
int getLast(int x){
    int ans = -1;
    For(i,0,30){
        if(bit(x, i) == 1){
            maximize(ans, i);
        }
    }
    return ans;
}
 
int get2(int n, int c){
    int ans = 0;
    Fod(i,30,c+1) if(bit(n, i)) ans |= (1 << i);
    ans |= (1 << c);
    return ans;
}
 
int get3(int n, int c){
    int ans = 0;
    Fod(i,30,c+1) if(bit(n, i)) ans |= (1 << i);
    Fod(i,c,0) ans |= (1<<i);
    return ans;
}
 
int get4(int n){
    if(n == 0) return 1e18;
    int l = getLast(n);
    int ans = 1 << l;
    --ans;
    return ans;
}
 
int get5(int n, int c){
    int ans = n, p = -1;
    For(i,c+1,30){
        if(bit(n, i)){
            ans -= (1<<i);
            p = i;
            break;
        }
    }
    if(p == -1) return 1e18;
    Fod(i,p-1,0) ans |= (1<<i);
    return ans;
}
 
void in(int n){
    Fod(i,30,0) cout << bit(n, i);
    cout << "\n";
}
 
void solve(){
    int tc; cin >> tc;
    while(tc--){
        int n, m; cin >> n >> m;
        int ans = n;
        // Fod(i,30,0) cout << bit(n, i); cout << "\n";
        For(i,0,30){
            int c = bit(n, i);
            if(c == 1) continue;
            int opt2 = get2(ans, i);
            int opt3 = get3(ans, i);
            int opt4 = get4(ans);
            int opt5 = get5(ans, i);
 
            // cout << i <<":\n";
            // in(ans);
            // in(opt2);
            // in(opt1);
            // in(opt3);
            // in(opt4);
            // in(opt5);
            // cout << "\n";
 
            if((bit(opt2, i) && abs(opt2-n)<=m)
                || (bit(opt3, i) && abs(opt3-n)<=m)
                || (bit(opt4, i) && abs(opt4-n)<=m)
                || (bit(opt5, i) && abs(opt5-n)<=m)){
                ans |= (1 << i);            
            }
        }
        cout << ans << "\n";
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