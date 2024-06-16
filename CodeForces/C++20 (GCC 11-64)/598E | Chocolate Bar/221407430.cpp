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
const int N = 55;
 
int n, m, k;
int dp[N][N][N];
 
int f(int n, int m, int k){
    if(dp[n][m][k] || n*m==k || k==0) return dp[n][m][k];
    int res = 1e9;
    For(i,1,n/2){
        For(j,0,k){
            res = min(res, m*m + f(i, m, j) + f(n-i, m, k-j));
        }
    }
    For(i,1,m/2){
        For(j,0,k){
            res = min(res, n*n + f(n, i, j) + f(n, m-i, k-j));
        }
    }
    return dp[n][m][k] = res;
}
 
void solve(){
    int n, m, k; cin >> n >> m >> k;
    cout << f(n, m, k) << "\n";
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
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}