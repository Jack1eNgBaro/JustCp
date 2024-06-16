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
const int N = 1e6 + 5;
 
int p[N+1];
void makeset(){
 For(i,0,N){
  p[i] = i;
 }
}
int find(int v){
 if(v == p[v]) return v;
 return p[v] = find(p[v]);
}
 
void Union(int a, int b){
 a = find(a);
 b = find(b);
 if(a == b) return;
 p[a] = b;
}
 
#define uwu pair<ii,int> 
vector<uwu> vec;
int n, q, a[N];
 
void solve(){
 makeset();
    cin >> n >> q;
    For(i,1,q){
     int l, r, w; cin >> l >> r >> w;
     vec.pb({{l, r}, w});
    }
    // reverse(all(vec));
    for(auto [it, w]: vec){
     int l = it.fi, r = it.se;
     while(l <= r){
      l = find(l);
      if(l > r) break;
   if(l != w){
    a[l] = w;
    Union(l, l + 1);
   }
   if(a[l-1]) Union(l - 1, l);  
   ++l;
     }
     // For(i,1,n) cout << a[i] << " "; cout << "\n";
    }
    For(i,1,n) cout << a[i] << " ";
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