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
#define Jack1e "Daubuoi bainao"
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
 
int n, val, a[N], dp[N][3];
 
//ket thuc tai
//0: chua 
//1: dang 
//2: roi
 
void solve(){
    cin >> n >> val;
    For(i,1,n) cin >> a[i];
 
    For(i,0,n){ 
        dp[i][1] = max(dp[i][0], dp[i][1]);
        dp[i][2] = max(dp[i][1], dp[i][2]);
 
        maximize(dp[i+1][0], max({dp[i][0], 0ll}) + a[i+1]);
        maximize(dp[i+1][1], max({dp[i][0], dp[i][1], 0ll}) + a[i+1]*val);
        maximize(dp[i+1][2], max({dp[i][0], dp[i][1], dp[i][2], 0ll}) + a[i+1]);
    }
    int ans = -1e18;
    For(j,0,2)  For(i,1,n){
        maximize(ans, dp[i][j]);
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