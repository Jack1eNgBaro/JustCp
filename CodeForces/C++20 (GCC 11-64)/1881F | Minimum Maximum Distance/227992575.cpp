#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
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
const int N = 1e6 + 5;
 
int dp[N], f[N];
int n, k, vjp[N];
vector<int> adj[N];
 
void reset(){
 memset(dp, 0, (n+5)*sizeof(int));
 memset(vjp, 0, (n+5)*sizeof(int));
 For(i,1,n){
  adj[i].clear();
 }
}
 
void go(int u, int p=-1){
 dp[u] = vjp[u];
 for(int v: adj[u]){
  if(v == p) continue;
  go(v, u);
  if(dp[v]) dp[u] = 1;
 }
}
 
void dfs(int u, int p=-1){
 for(int v: adj[u]){
  if(v == p) continue;
  f[v] = f[u] + 1;
  dfs(v, u);
 }
}
 
void solve(){
    cin >> n >> k;
    reset();
    int root = -1;
    For(i,1,k){
     int x; cin >> x;
     vjp[x] = 1;
     root = x;
    }
    For(i,2,n){
     int x, y; cin >> x >> y;
     adj[x].pb(y);
     adj[y].pb(x);
    }
    go(root);
 
 
    int mx = -1;
    memset(f, 0, (n+5)*sizeof(int));
    dfs(root);
    For(i,1,n){
     if(dp[i] && maximize(mx, f[i])){
      root = i;
     }
    }
 
    int mx2 = -1;
    memset(f, 0, (n+5)*sizeof(int));
    dfs(root);
    For(i,1,n){
     if(dp[i] && maximize(mx2, f[i])){
      root = i;
     }
    }
 
    cout << (mx2 + 1) / 2 << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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