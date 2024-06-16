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
 
int n, k, q, a[N];
 
int sg[4*N], cc[N];
void build(int id, int l, int r){
 if(l == r){
  sg[id] = a[l];
  cc[id] = 1;
  return;
 }
 int m = (l + r) / 2;
 
 build(id * 2, l, m);
 build(id * 2 + 1, m + 1, r);
 
 if(cc[id << 1] == 1){
  sg[id] = sg[id*2] | sg[id*2+1];
 }else{
  sg[id] = sg[id*2] ^ sg[id*2+1];
 }
 cc[id] = cc[id*2] ^ 1;
}
 
void update(int id, int l, int r, int pos, int val){
 if(pos < l || pos > r) return;
 if(l == r){
  sg[id] = val;
  return;
 }
 int m = (l + r) / 2;
 update(id * 2, l, m, pos, val);
 update(id * 2 + 1, m + 1, r, pos, val);
 if(cc[id << 1] == 1){
  sg[id] = sg[id*2] | sg[id*2+1];
 }else{
  sg[id] = sg[id*2] ^ sg[id*2+1];
 }
}
 
void solve(){
    cin >> k >> q;
    n = 1 << k;
    For(i,1,n) cin >> a[i];
 
    build(1, 1, n);
    while(q--){
     int p, b; cin >> p >> b;
     update(1, 1, n, p, b);
     cout << sg[1] << "\n";
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