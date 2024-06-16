#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
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
 
const int M = 26;
const int N = 2e5 + 5;
 
int n, Q;
string str;
 
struct node{
 int cnt[M];
 node(){
  memset(cnt, 0, sizeof(cnt));
 }
};
 
node merge(node a, node b){
 node ans;
 For(i,0,25){
  ans.cnt[i] = (a.cnt[i] + b.cnt[i]);
 }
 return ans;
}
 
class segTree{
public:
 vector<node> sg;
 void resize(int n){
  sg = vector<node>(4*n);
 }
 void build(int id, int l, int r){
  if(l == r){
   sg[id].cnt[str[l]-'a']++;
   return;
  }
  int m = l + r >> 1;
  build(id << 1, l, m);
  build(id << 1 | 1, m + 1, r);
  sg[id] = merge(sg[id << 1], sg[id << 1 | 1]);
 }
 
 void update(int id, int l, int r, int pos, char ch){
  if(pos < l || pos > r) return;
  if(l == r){
   sg[id].cnt[str[pos]-'a']--;
   sg[id].cnt[ch-'a']++;
   return;
  }
  int m = l + r >> 1;
  update(id << 1, l, m, pos, ch);
  update(id << 1 | 1, m + 1, r, pos, ch);
  sg[id].cnt[str[pos]-'a']--;
  sg[id].cnt[ch-'a']++;
  // sg[id] = merge(sg[id << 1], sg[id << 1 | 1]);
 }
 
 node get(int id, int l, int r, int u, int v){
  if(l > v || r < u){
   node tmp; return tmp;
  }
  if(l >= u && r <= v) return sg[id];
  int m = l + r >> 1;
  node n1 = get(id << 1, l, m, u, v);
  node n2 = get(id << 1 | 1, m + 1, r, u, v);
  return merge(n1, n2);
 }
 
 
};
 
segTree segchi;
void solve(){
 cin >> str;
 n = str.size();
 str = "~" + str;
 
 segchi.resize(n);
 segchi.build(1, 1, n);
 
 cin >> Q;
 while(Q--){
  int type; cin >> type;
  if(type == 1){
   int pos; char c; 
   cin >> pos >> c;
   segchi.update(1, 1, n, pos, c);
   str[pos] = c;
  }else{
   int l, r; cin >> l >> r;
   node gg = segchi.get(1, 1, n, l, r);
   int ans = 0;
   For(i,0,25) ans += (gg.cnt[i] > 0);
   cout << ans << "\n";
  }
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