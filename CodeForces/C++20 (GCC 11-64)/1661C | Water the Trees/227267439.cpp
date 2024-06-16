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
 
int n, a[N];
int kt(int need, int mid){
 int cnt1 = (mid + 1) / 2, cnt2 = mid - cnt1;
 int need1 = 0;
 For(i,1,n){
  int cur = (need - a[i]) / 2;
 
  if((need - a[i]) % 2 == 1){
   ++need1;
  }
  
  if(cnt2 >= cur){
   cnt2 -= cur;
  }else{
   cur -= cnt2;
   cnt2 = 0;
   need1 += cur * 2;
  }
 }
 if(need1 <= cnt1) return 1;
 return 0;
}
 
void solve(){
 cin >> n;
 For(i,1,n) cin >> a[i];
 sort(a + 1, a + n + 1);
 
 int mx = a[n];
 int res = 1e18;
 for(int need: {mx, mx + 1}){
  int ans = 1e18;
  int l = 0, r = 1e18;
  while(l <= r){
   int m = (l + r) / 2;
   if(kt(need, m)){
    ans = m;
    r = m - 1;
   }else l = m + 1;
  }
  minimize(res, ans);
 }
 cout << res << "\n";
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