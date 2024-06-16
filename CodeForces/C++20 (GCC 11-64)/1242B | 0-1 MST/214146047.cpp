#include<bits/stdc++.h>
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
 
int n, m;
set<int> adj[N];
set<int> s;
 
int bfs(int i){
 queue<int> q; 
 q.push(i);
 s.erase(i);
 int cnt = 0;
 
 while(q.size()){
  int u = q.front(); q.pop();
  cnt++;
  vector<int> vec;
  for(int v: s){
   if(!adj[u].count(v)){
    q.push(v);
    vec.pb(v);
   }
  } 
  for(auto x: vec){
   s.erase(x);
  }
 }
 return cnt;
}
 
void solve(){
    cin >> n >> m;
    For(i,1,m){
     int x, y; cin >> x >> y;
     adj[x].insert(y);
     adj[y].insert(x);
    }
    For(i,1,n) s.insert(i);
    vector<int> v;
    For(i,1,n){
     if(!s.count(i)) continue;
     v.pb(bfs(i));
    }
    cout << v.size() - 1 << "\n";
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