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
const int N = 45;
 
int n, m, q;
int a[N][N], f[N][N], dp[N][N][N][N], g[N][N][N][N];
 
int kt(int i, int j, int u, int v){
    int ans = f[u][v] - f[u][j-1] - f[i-1][v] + f[i-1][j-1];
    return ans == 0;
}
 
int get(int x, int y, int u, int v, int len, int s){
    int ans = 
        g[len][s][u][v] - g[len][s][u][y-1] - g[len][s][x-1][v]
            + g[len][s][x-1][y-1];
    return ans;
}
 
void solve(){
    cin >> n >> m >> q;
    For(i,1,n)  For(j,1,m){
        char c; cin >> c;
        a[i][j] = (c == '1');
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
    }
 
    For(len,1,n)
    For(s,1,m){
        For(i,len,n){
            int cnt = 0;            
            For(j,s,m){
                if(kt(i-len+1, j, i, j)){
                    ++cnt;
                }else{
                    cnt = 0;
                }
                dp[len][s][i][j] = cnt;
            }
        }
    }
    
    For(len,1,n)    For(s,1,m){
        For(i,len,n)  For(j,s,m){
            g[len][s][i][j] = g[len][s][i-1][j] + g[len][s][i][j-1]
                 - g[len][s][i-1][j-1] + dp[len][s][i][j]; 
        }
    }
 
    while(q--){
        int ans = 0;
        int x, y, u, v;
            cin >> x >> y >> u >> v;
        for(int len=1;x+len-1<=u&&u-len+1>=x;len++){
            ans += get(x+len-1, y, u, v, len, y);
            
        }
        cout << ans << "\n";
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