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
const int N = 42;
 
int n, m, q;
int a[N][N];
 
int kt(int x, int y, int u, int v){
    int ans = a[u][v] - a[u][y-1] - a[x-1][v] + a[x-1][y-1];
    return ans == 0;
}
 
int f[N][N][N][N];
int get(int x, int y, int u, int v, int st, int len){
    int ans = 
        f[len][st][u][v] - f[len][st][u][y-1] - f[len][st][x-1][v]
    +   f[len][st][x-1][y-1];
    return ans;
}
 
void solve(){
    cin >> n >> m >> q;
    For(i,1,n)  For(j,1,m){
        char c; cin >> c;
        a[i][j] = (c == '1'); 
    }
    For(i,1,n)  For(j,1,m)  a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
 
    For(st,1,m) For(len,1,n){
        for(int i=len;i<=n;i++){
            int c = 0;
            For(j,st,m){
                if(kt(i-len+1, j, i, j)){
                    f[len][st][i][j] = ++c;
                }else{
                    f[len][st][i][j] = c = 0;   
                }
            }
        }
    }
 
    For(st,1,m) For(len,1,n)
    For(i,len,n)  For(j,st,m){
        f[len][st][i][j] += 
            f[len][st][i-1][j] + f[len][st][i][j-1] - f[len][st][i-1][j-1];
    }
 
    while(q--){
        int x, y, u, v; cin >> x >> y >> u >> v;
        int ans = 0;
        for(int len=1;x+len-1<=u && u-len+1>=x;len++){
            ans += get(x+len-1, y, u, v, y, len);
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