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
const int N = 2e5 + 5;
 
int n, k, in[N+1], a[N+1], f[N+1];
vector<int> adj[N+1], radj[N+1]; 
 
void reset(int n){
 For(i,1,n){
  in[i] = 0;
  f[i] = 0;
  adj[i].clear();
  radj[i].clear();
 }
}
 
void solve(){
 cin >> n >> k;
 reset(n);
 For(i,1,n) cin >> a[i];
 For(i,1,k){
  int x; cin >> x;
  a[x] = 0;
  // f[x] = 1;
 }
 For(i,1,n){
  int m; cin >> m;
  while(m--){
   int x; cin >> x;
   adj[x].pb(i);
   in[i]++;
   radj[i].pb(x);
  }
 }
 
 queue<int> q;
 For(i,1,n) if(in[i] == 0){
   q.push(i);
   f[i] = 1;
 }
 
 while(q.size()){
  int u = q.front(); q.pop();
  // cout << u << ' ';
  for(int v: adj[u]){
   in[v]--;
   if(in[v] == 0) q.push(v);
  }
  if(!f[u]){
   int sum = 0;
   for(int v: radj[u]){
    sum += a[v];
   }
   a[u] = min(sum, a[u]);
  }
 }
 For(i,1,n) cout << a[i] << ' '; cout << "\n";
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
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}