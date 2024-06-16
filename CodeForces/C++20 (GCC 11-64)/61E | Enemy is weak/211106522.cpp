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
const int N = 1e6+5;
 
int bit[N];
//0: len, 1 xuong
void add(int id, int c){
 if(c == 0){
  while(id <= N){
   bit[id]++;
   id += id & (-id);
  }
 }else{
  while(id >= 1){
   bit[id]++;
   id -= id & (-id);
  }
 }
}
 
 
int get(int id, int c){
 int ans = 0;
 if(c == 0){
  while(id <= N){
   ans += bit[id];
   id += id & (-id);
  }
 }else{
  while(id >= 1){
   ans += bit[id];
   id -= id & (-id);
  }
 }
 return ans;
}
 
int n, a[N], f[N], g[N];
vector<int> v;
void solve(){
 cin >> n;
 For(i,1,n){
  cin >> a[i];
  v.pb(a[i]);
 }
 sort(v.begin(), v.end());
 For(i,1,n) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
 
 Fod(i,n,1){
  g[i] = get(a[i], 1);
  add(a[i], 0);
 }
 memset(bit, 0, sizeof(bit));
 ll ans = 0;
 For(i,1,n-1){
  f[i] = get(a[i], 0);
  add(a[i], 1);
  ans += 1ll * f[i] * g[i];
 }
 cout << ans;
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