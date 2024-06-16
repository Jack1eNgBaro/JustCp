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
 
int n, a[N], b[N];
int st[N][20];
 
int get(int l, int r){
 int k = log2(r-l+1);
 int x = st[l][k];
 int y = st[r-(1<<k)+1][k];
 return __gcd(x, y);
}
 
void solve(){
 cin >> n;
 For(i,1,n) cin >> b[i];
 --n;
 For(i,1,n) a[i] = abs(b[i+1]-b[i]);
 For(i,1,n) st[i][0] = a[i];
 for(int j=1;(1<<j)<=n;j++){
  for(int i=1;i+(1<<(j-1))<=n;i++){
   st[i][j] = __gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
  }
 }
 
 int g = 0, ans = 0;
 for(int l=1,i=1;i<=n;i++){
  g = get(l, i);
  while(l <= i && g <= 1){
   ++l;
   g = get(l, i);
  }
  if(g > 1){
   maximize(ans, i - l + 1);
  }
 }
 cout << ans + 1 << "\n";
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