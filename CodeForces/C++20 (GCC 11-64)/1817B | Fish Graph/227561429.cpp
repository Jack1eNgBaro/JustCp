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
const int N = 2005 + 5;
 
int n, m;
vector<int> adj[N];
int used[N], par[N];
 
bool check(int s, int t){ //chu trinh bat dau tai s, ket thuc tai t
 For(i,1,n){
  used[i] = 0;
  par[i] = -1;
 }
 queue<int> q;
 q.push(s);
 // cout << "\n" << s << " " << t << "\n";
 
 used[s] = 1;
 while(q.size()){
  int u = q.front(); q.pop();
  // cout << u << ' ';
  for(int v: adj[u]){
   if(u == s && v == t) continue;
   if(u == t && v == s) return 1;
   if(used[v]) continue;
   q.push(v);
   par[v] = u;
   used[v] = 1;
  }
 }
 return 0;
} 
 
vector<int> get(int t, int s){
 vector<int> ans;
 while(s != t){
  ans.pb(s);
  s = par[s];
 }
 ans.pb(s);
 return ans;
}
 
void solve(){
    cin >> n >> m;
    For(i,1,n) adj[i].clear();
    For(i,1,m){
     int x, y; cin >> x >> y;
     adj[x].pb(y);
     adj[y].pb(x);
    }
    For(i,1,n){
     for(int j: adj[i]){
      if(adj[i].size() >= 4 && check(i, j)){
       // cout << "\n";
       // cout << i << ' ' << j << "\n";
       auto tmp = get(i, j); 
       // for(auto x: tmp) cout << x << " ";
 
       set<int> se;
       for(auto x: tmp) se.insert(x);
 
       vector<int> sv;
       for(auto v: adj[i]){
        if(!se.count(v)){
         sv.pb(v);
        }
       }
       if(sv.size() >= 2){
     cout << "YES\n";
     cout << tmp.size() + 2 << "\n";
     cout << i << ' ' << sv[0] << "\n";
     cout << i << ' ' << sv[1] << "\n";
     for(int k=1;k<tmp.size();k++){
      cout << tmp[k-1] << ' ' << tmp[k] << "\n";
     }
     cout << tmp.back() << ' ' << tmp[0] << "\n";
     return;
    }
      }
     }
    }
    cout << "NO\n";
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