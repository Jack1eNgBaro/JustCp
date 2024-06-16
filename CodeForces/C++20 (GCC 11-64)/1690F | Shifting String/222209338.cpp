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
 
int n, p[N], used[N];
string s;
vector<int> adj[N], radj[N];
stack<int> st;
int ans[N];
 
int gcd(int a, int b){
 if(b == 0) return a;
 return gcd(b, a % b);
}
int lcm(int a, int b){
 return a / gcd(a, b) * b;
}
 
void dfs1(int u, int p=-1){
 used[u] = 1;
 for(int v: adj[u]){
  if(v == p) continue;
  if(used[v] == 0) dfs1(v, u);
 }
 st.push(u);
}
 
void dfs2(int u, vector<int> &vec, int p){
 used[u] = 1;
 vec.pb(u);
 for(int v: radj[u]){
  if(v == p) continue;
  if(used[v] == 0) dfs2(v, vec, u);
 }
}
 
string shift(string str){
 auto t = str.back();
 str.pop_back();
 str = t + str;
 return str;
}
 
void solve(){
 cin >> n >> s;
 s = "~" + s;
 
 For(i,1,n){
  adj[i].clear();
  radj[i].clear();
  ans[i] = 0;
 }
 
 For(i,1,n){
  cin >> p[i];
  adj[i].pb(p[i]);
  radj[p[i]].pb(i);
 }
 
 For(i,1,n) used[i] = 0;
 For(i,1,n){
  if(used[i] == 0) dfs1(i, -1);
 }
 
 int res = -1;
 For(i,1,n) used[i] = 0;
 while(st.size()){
  int u = st.top(); st.pop();
  if(used[u] == 1) continue;
  vector<int> vec;
  dfs2(u, vec, -1);
  for(auto x: vec){
   ans[x] = vec.size();
  }
 
  //ko can phai di het chu trinh
  // if(res == -1) res = vec.size();
  // else res = lcm(res, (int)vec.size());
 
  //in ra xem kq
  // for(auto x: vec) cout << x << ' '; cout << "\n";
 
  string tmp = "";
  for(auto x: vec) tmp += s[x];
  string mt = shift(tmp);   
  int cnt = 1;
  while(mt != tmp){
   mt = shift(mt);
   ++cnt;
  }
  if(res == -1) res = cnt;
  else{
   res = lcm(res, cnt);
  }
 
 
  //sai
  // reverse(all(vec));
  // int sz = vec.size();
  // for(int i=0;i<vec.size();i++) for(int j=0;j<vec.size();j++){
  //  if(i == j) continue;
  //  int x = vec[i];
  //  int y = vec[j];
  //  if(s[x] == s[y]){
  //   if(i < j) minimize(ans[x], j - i);
  //   else minimize(ans[x], sz - i + j);
  //  }
  // }
 }
 
 // For(i,1,n) cout << ans[i] << ' ';
 
 // int res = ans[1];
 // For(i,2,n) res = lcm(res, ans[i]);
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