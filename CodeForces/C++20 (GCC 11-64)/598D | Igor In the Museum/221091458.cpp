#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
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
const int N = 1111;
 
int n, m, Q, a[N][N];
int cnt = 0, used[N][N];
int id[N][N];
vector<ii> mems[1111111];
unordered_map<int,int> mp;
 
int nhucc(int i, int j){
 return (i >= 1 && i <= n && j >= 1 && j <= m);
}
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
 
void dfs(int u, int v){
 used[u][v] = 1; 
 mems[cnt].pb({u, v});
 id[u][v] = cnt;
 For(k,0,3){
  int u1 = u + dx[k];
  int v1 = v + dy[k];
  if(nhucc(u1, v1) && a[u1][v1] == 0 && !used[u1][v1]){
   dfs(u1, v1);
  }
 }
}
 
int count(int id){
 int ans = 0;
 for(auto [x, y]: mems[id]){
  For(k,0,3){
   int x1 = x + dx[k];
   int y1 = y + dy[k];
   if(nhucc(x1, y1) && a[x1][y1] == 1)++ans;
  }
 }
 return ans;
}
 
void solve(){
    cin >> n >> m >> Q;
    For(i,1,n) For(j,1,m){
     char c; cin >> c;
     if(c == '*') a[i][j] = 1;
     else a[i][j] = 0;
    }
    For(i,1,n) For(j,1,m){
     if(a[i][j] == 0 && used[i][j] == 0){
      ++cnt;
      dfs(i, j);
     }
    }
 
    while(Q--){
     int x, y; cin >> x >> y;
     auto p = id[x][y];
     if(!mp.count(p)){
      mp[p] = count(p);
     }
     cout << mp[p] << "\n";
    }
 
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