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
const int N = 5005;
 
int n, m;
int a[N][N];
 
int s, t, u, v;
 
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
 
int valid(int i, int j){
 return (i >= 1 && i <= n && j >= 1 && j <= m);
}
 
int ok = 0;
void dfs(int i, int j){
 if(ok) return;
 // cout << i << " " << j << "\n";
 for(int k=0;k<4;k++){
  int i1 = i + dx[k];
  int j1 = j + dy[k];
  if(!valid(i1, j1)) continue;
 
  if(a[i1][j1] == 1){
   if(i1 == u && j1 == v)
    return ok = 1, void();
  }
  if(a[i1][j1] == 0){
   a[i1][j1] = 1;
   dfs(i1, j1);
  }
 }
}
 
void solve(){
 cin >> n >> m;
 For(i,1,n) For(j,1,m){
  char c; cin >> c;
  if(c == 'X') a[i][j] = 1;
  else a[i][j] = 0;
 }
 cin >> s >> t >> u >> v;
 dfs(s, t);
 if(ok) cout << "YES\n";
 else cout << "NO\n";
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