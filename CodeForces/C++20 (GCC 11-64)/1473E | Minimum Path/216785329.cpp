#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
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
const int N = 5e5 + 5;
 
int n, m, dp[N][2][2];
vector<ii> adj[N];
#define uwu pair<ii,ii>
 
void solve(){
    cin >> n >> m;
    For(i,1,m){
        int x, y, w; cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
 
    memset(dp, 0x3f, sizeof(dp));
    priority_queue<uwu, vector<uwu>, greater<uwu>> q;
    q.push({{0, 1}, {0, 0}});
    dp[1][0][0] = 0;
    
    while(q.size()){
        auto it = q.top(); q.pop();
        int dis = it.fi.fi;
        int u = it.fi.se;
        int x = it.se.fi;
        int y = it.se.se;
 
        if(dis != dp[u][x][y]) continue;
        // cout << dis << ' ' << u << ' ' << x << ' ' << y << "\n";
 
        for(auto [v, w]: adj[u]){
            if(dp[v][x][y] > dis + w){
                dp[v][x][y] = dis + w;
                q.push({{dp[v][x][y], v}, {x, y}});
            }
            if(x == 0 && y == 0){
                if(dp[v][x+1][y+1] > dis + w){
                    dp[v][x+1][y+1] = dis + w;
                    q.push({{dp[v][x+1][y+1], v}, {x+1, y+1}});
                }
            }
            if(x == 0){
                if(dp[v][x+1][y] > dis){
                    dp[v][x+1][y] = dis;
                    q.push({{dp[v][x+1][y], v}, {x+1, y}});
                }
            }
            if(y == 0){
                if(dp[v][x][y+1] > dis + 2*w){
                    dp[v][x][y+1] = dis + 2*w;
                    q.push({{dp[v][x][y+1], v}, {x, y+1}});
                }
            }
        }
    }
    For(i,2,n) cout << dp[i][1][1] << ' ';
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