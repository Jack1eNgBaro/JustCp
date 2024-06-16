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
const int N = 1e6 + 5;
 
int n, k, h[N], sz[N], xa[N];
vector<int> adj[N];
 
void dfs(int u, int p=-1){
 // xa[u] = 0;
 sz[u] = 1;
 for(int v: adj[u]){
  if(v == p) continue;
  h[v] = h[u] + 1;
  dfs(v, u);
  // xa[u] = max(xa[u], xa[v] + 1);
  sz[u] += sz[v];
 }
}
 
vector<int> vec;
 
void solve(){
    cin >> n >> k;
    For(i,2,n){
     int x, y; cin >> x >> y;
     adj[x].pb(y);
     adj[y].pb(x);
    }
    dfs(1);
    For(i,1,n) vec.pb(i);
    sort(all(vec), [](int a, int b){
     return h[a] - sz[a] > h[b] - sz[b];
     // if(h[a] != h[b]) return h[a] > h[b];
     // return xa[a] < xa[b];
    });
 
    int ans = 0;
    For(i,1,n){
     int x = vec[i-1];
     int w = h[x] - sz[x] + 1;
     if(k >= 1){
      // cout << x << ' ' << w << "\n";
      ans += w;
      --k;
     }
    }
    cout << ans;
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