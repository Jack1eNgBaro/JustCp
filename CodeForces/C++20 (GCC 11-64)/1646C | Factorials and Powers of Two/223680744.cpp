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
const int N = 15;
 
vector<int> a;
void init(){
    int cur = 1;
    For(i,1,N){
        cur *= i;
        a.pb(cur);
    }
}
 
void minisol(int n){
    int ans = __builtin_popcountll(n);
    for(int x=0;x<(1<<N);x++){
        int sum = 0;
        for(int i=0;i<N;i++){
            if(bit(x, i)) sum += a[i];
        }
        if(n - sum < 0) continue;
 
        int cnt = __builtin_popcountll(x);
        int tmp = __builtin_popcountll(n - sum) + cnt;
        minimize(ans, tmp);
    }
    if(ans == 1e9) ans = -1;
    cout << ans << "\n";
}
 
void solve(){
    init();
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        minisol(n);
    }        
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