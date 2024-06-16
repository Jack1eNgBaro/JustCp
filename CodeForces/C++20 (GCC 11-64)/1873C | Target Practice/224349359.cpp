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
const int N = 10;
 
int a[N+5][N+5];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
 
int n = N;
#define uwu pair<ii,int> 
 
void solve(){
 queue<uwu> q;
 memset(a, -1, sizeof(a));
 For(i,1,n) For(j,1,n){
  char c; cin >> c;
  a[i][j] = (c == 'X');
 }
 
 int ans = 0;
 For(i,1,n) For(j,1,n){
  if(i == 1 || j == 1 || i == n || j == n){
   q.push({{i, j}, 1});
   if(a[i][j] == 1) ++ans;
   a[i][j] = -1;
  }
 }
 
 while(q.size()){
  auto [it, w] = q.front(); q.pop();
  For(k,0,3){
   int x1 = it.fi + dx[k];
   int y1 = it.se + dy[k];
   if(x1 < 1 || x1 > n || y1 < 1 || y1 > n) continue;
   if(a[x1][y1] == -1) continue;
   q.push({{x1, y1}, w + 1});
   ans += a[x1][y1] * (w + 1);
   a[x1][y1] = -1;
  }
 }
 
 cout << ans << "\n";
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