#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#define MOD 1000000007
#define fi first
#define se second
#define ll long long
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
const int N = 5005;
 
int n, h, l, r, a[N];
int dp[N][N];
 
void solve(){
    cin >> n >> h >> l >> r;
    For(i,1,n) cin >> a[i];
 
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    For(i,0,n){
     For(j,0,h-1){
      int opt1 = (j + a[i + 1]) % h;
      int opt2 = (j + a[i + 1] - 1) % h;
 
      if(opt1 < 0) opt1 += h;
      if(opt2 < 0) opt2 += h;
 
      maximize(dp[i + 1][opt1], 
       dp[i][j] + (opt1 >= l && opt1 <= r));
      maximize(dp[i + 1][opt2], 
       dp[i][j] + (opt2 >= l && opt2 <= r));
     }
    }
    int ans = 0;
    For(j,0,h-1) maximize(ans, dp[n][j]);
    cout << ans;
}
 
int main(){
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