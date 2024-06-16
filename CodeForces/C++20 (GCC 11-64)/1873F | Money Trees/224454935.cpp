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
const int N = 2e5 + 5;
 
int n, k;
int a[N], h[N], en[N];
 
class segtree{
public:
 vector<int> sg;
 void resize(int n){
  sg = vector<int>(4*n + 5, 0);
 }
 void build(int id, int l, int r){
  if(l == r){
   sg[id] = a[l];
   return;
  }
  int m = l + r >> 1;
  build(id << 1, l, m);
  build(id << 1 | 1, m + 1, r);
  sg[id] = min(sg[id << 1], sg[id << 1 | 1]);
 }
 // f[j] - f[i-1] <= k
 // f[j] <= f[i-1] + k;
 int get(int id, int l, int r, int val){
  if(l == r){
   if(sg[id] <= val) return l;
   return -1;
  }
  int m = (l + r) / 2;
  if(sg[id*2+1] <= val){
   return get(id*2+1, m+1, r, val);
  }else if(sg[id*2] <= val){
   return get(id*2, l, m, val);
  }
  return -1;
 } 
};
 
void solve(){
    cin >> n >> k;
    For(i,0,n) a[i] = h[i] = en[i] = 0;
 
    For(i,1,n) cin >> a[i];
    For(i,1,n){
     cin >> h[i];
     en[i] = i;
    }
    Fod(i,n-1,1) if(h[i] % h[i+1] == 0){
     en[i] = en[i+1];
    }
    
    // For(i,1,n) cout << en[i] << ' '; cout << "\n";
 
    segtree seg;
    seg.resize(n);
 
    For(i,1,n) a[i] += a[i-1];
    seg.build(1, 1, n);
 
    int ans = 0;
    For(i,1,n){
     int pos = seg.get(1, 1, n, a[i-1] + k);
     if(pos == -1 || pos < i) continue;
     if(pos > en[i]) pos = en[i];
     maximize(ans, pos - i + 1);
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