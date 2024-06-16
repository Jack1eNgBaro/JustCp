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
const int N = 505;
 
int a[N][N];
 
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
void solve(){
  int tc; cin >> tc;
  while(tc--){
   memset(a, 0, sizeof(a));
   int n, m; cin >> n >> m;
   for(int i=1;i<=n;i+=2){
    if(i == 1 || i == n){
     for(int j=1;j<=m;j+=2){
      a[i][j] = 1;
     }
    }else{
     a[i][1] = a[i][m] = 1;
    }
   }
   for(int i=1;i<=m;i++){
    int x = n;
    int y = i;
    int s = 0;
    For(d,0,7) s += a[x+dx[d]][y+dy[d]];
    if(s == 0){
     a[x][y] = 1;
    }
   }
   For(i,1,n){
    For(j,1,m){
      cout << a[i][j];
    }cout << "\n";
   }
   cout <<"\n";
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