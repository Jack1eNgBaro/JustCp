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
const int N = 2e5 + 5;
 
void solve(){
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  vector<int> a, b;
 
  ll mx = -1e18;
  For(i,1,n){
   int x; cin >> x;
   if(i&1) a.pb(x);
   else b.pb(x);
   mx = max(mx, 1ll*x);
  } 
 
  ll ans = mx;
  ll s = 0, ok = 0;
  for(int x: a){
   if(x > 0){
    ok = 1;
    s += x;
   }
  }
  if(ok) ans = max(ans, s);
  s = 0; ok = 0;
  for(int x: b){
   if(x > 0){
    s += x;
    ok = 1;
   }
  }
  if(ok) ans = max(ans, s);
  cout << ans << "\n";
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