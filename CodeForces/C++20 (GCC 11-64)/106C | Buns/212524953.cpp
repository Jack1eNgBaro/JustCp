#include<bits/stdc++.h>
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
 
const int N = 1005;
const int inf = 1e9;
 
int n, m;
struct ele{
    int a, b, c, d;
};
ele arr[N];
 
int dp[N][N];
void solve(){
    cin >> n >> m;
    int tmp1, tmp2; cin >> tmp1 >> tmp2;
    arr[1] = {inf, 1, tmp1, tmp2};
    For(i,2,m+1){
        int a, b, c, d; cin >> a >> b >> c >> d;
        arr[i] = {a, b, c, d};
    }
    ++m;
    For(i,1,m){
        For(s,1,n){
            dp[i][s] = dp[i-1][s];
            auto it = arr[i];
            int sz = min(n/it.c, it.a/it.b);
            For(j,1,sz){
                if(s >= it.c*j){
                    maximize(dp[i][s], dp[i-1][s-it.c*j] + it.d*j);
                }
            }
        }
    }
    // For(i,1,m)  For(s,1,n){
    //     cout << i << " " << s << ": " << dp[i][s] << "\n";
    // }
    cout << dp[m][n];
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