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
 
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
 
int n, m, old_val[N];
vector<int> 
 old_adj[N], old_radj[N];
 
//Fuking kosaraju =v
int used[N];
stack<int> st;
void dfs_1(int u){
 used[u] = 1;
 for(int v: old_adj[u]){
  if(used[v] == 1) continue;
  dfs_1(v);
 }
 st.push(u);
}
 
int val[N], cur_id = 0;
int mi[N], cnt[N];
void dfs_2(int u){
 used[u] = 1;
 
 int i = cur_id;
 if(old_val[u] < mi[i]){
  mi[i] = old_val[u];
  cnt[i] = 1;
 }else if(old_val[u] == mi[i]){
  ++cnt[i];
 }
 
 for(int v: old_radj[u]){
  if(used[v] == 1) continue;
  dfs_2(v);
 }
}
 
void kosaraju(){
 memset(used, 0, sizeof(used));
 For(i,1,n) if(used[i] == 0) dfs_1(i);
 memset(used, 0, sizeof(used));
 while(st.size()){
  int u = st.top(); st.pop();
  if(used[u] == 1) continue;
  ++cur_id;
  dfs_2(u);
 }
}
 
void solve(){
    cin >> n;
    For(i,1,n) cin >> old_val[i];
    cin >> m;
    For(i,1,m){
     int x, y; cin >> x >> y;
     old_adj[x].pb(y);
     old_radj[y].pb(x);
    }
    memset(mi, 0x3f, sizeof(mi));
    kosaraju();
    int sz = cur_id;
 
    int sum = 0, dem = 1;
    For(i,1,sz){
     sum += mi[i];
     dem = (dem * cnt[i]) % mod;
    }
    cout << sum << ' ' << dem;
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