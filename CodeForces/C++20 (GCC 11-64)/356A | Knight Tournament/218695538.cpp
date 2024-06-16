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
 
int n, q;
int sg[4*N], lz[4*N];
 
void down(int id){
 if(lz[id]){
  sg[id * 2] = sg[id * 2 + 1] = sg[id];
  lz[id * 2] = lz[id * 2 + 1] = 1;
  lz[id] = 0;
 }
}
 
void update(int id, int l, int r, int u, int v, int val){
 if(l > v || r < u) return;
 if(l >= u && r <= v){
  sg[id] = val;
  lz[id] = 1;
  return;
 }
 down(id);
 int m = (l + r) / 2;
 update(id * 2, l, m, u, v, val);
 update(id * 2 + 1, m + 1, r, u, v, val);
 sg[id] = max(sg[id * 2], sg[id * 2 + 1]);
}
 
int get(int id, int l, int r, int pos){
 if(pos < l || pos > r) return 0;
 if(l == r){
  return sg[id];
 }
 down(id);
 int m = (l + r) / 2;
 int g1 = get(id * 2, l, m, pos);
 int g2 = get(id * 2 + 1, m + 1, r, pos);
 return max(g1, g2);
}
 
#define uwu pair<ii,int>
vector<uwu> vec;
 
void solve(){
    cin >> n >> q;
    while(q--){
     int l, r, w; cin >> l >> r >> w;
     vec.pb({{l, r}, w});
    }
    reverse(all(vec));
    for(auto [it, w]: vec){
     int l = it.fi, r = it.se;
     update(1, 1, n, l, w-1, w);
     update(1, 1, n, w+1, r, w);
    }
    For(i,1,n) cout << get(1, 1, n, i) << " ";
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