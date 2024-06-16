#include<bits/stdc++.h>
// #pragma GCC optimize("O2")
// #pragma GCC target("avx,avx2,fma")
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
const int N = 1e5 + 5;
 
string str;
int n, Q, a[N];
int sg[3*N][2], lz[3*N];
 
void build(int id, int l, int r){
 if(l == r){
  if(str[l] == '0'){
   sg[id][0] = a[l];
   sg[id][1] = 0;
  }
  else{
   sg[id][1] = a[l];
   sg[id][0] = 0;
  }
  return;
 }
 int m = l + r >> 1;
 build(id << 1, l, m);
 build(id << 1 | 1, m + 1, r);
 sg[id][0] = (sg[id << 1][0] ^ sg[id << 1 | 1][0]);
 sg[id][1] = (sg[id << 1][1] ^ sg[id << 1 | 1][1]);
}
 
void update(int id, int l, int r, int u, int v){
 if(l > v || r < u) return;
 if(l >= u && r <= v){
  swap(sg[id][0], sg[id][1]);
  lz[id] ^= 1;
  return;
 }
 int m = l + r >> 1;
 if(lz[id]){
  update(id << 1, l, m, l, m);
  update(id << 1 | 1, m + 1, r, m + 1, r);
  lz[id] = 0;
 }
 update(id << 1, l, m, u, v);
 update(id << 1 | 1, m + 1, r, u, v);
 sg[id][0] = (sg[id << 1][0] ^ sg[id << 1 | 1][0]);
 sg[id][1] = (sg[id << 1][1] ^ sg[id << 1 | 1][1]);
}
 
int get(int id, int l, int r, int u, int v, int c){
 if(l > v || r < u) return 0;
 if(l >= u && r <= v){
  return sg[id][c];
 }
 int m = l + r >> 1;
 if(lz[id]){
  update(id << 1, l, m, l, m);
  update(id << 1 | 1, m + 1, r, m + 1, r);
  lz[id] = 0;
 }
 return get(id << 1, l, m, u, v, c) 
  ^ get(id << 1 | 1, m + 1, r, u, v, c);
}
 
void solve(){
 memset(sg, 0, sizeof(sg));
 memset(lz, 0, sizeof(lz));
    cin >> n;
    For(i,1,n) cin >> a[i];
    cin >> str;
    str = "~" + str;
    build(1, 1, n);
    cin >> Q;
    while(Q--){
     int type; cin >> type;
     if(type == 2){
      int c; cin >> c;
      cout << get(1, 1, n, 1, n, c) << " ";
     }else{
      int l, r; cin >> l >> r;
      update(1, 1, n, l, r);
     }
    }
    cout << "\n";
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