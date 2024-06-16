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
const int N = 3e5 + 5;
 
int par[N];
int find(int v){
 if(par[v] == 0) return v;
 return par[v] = find(par[v]);
}
void Union(int a, int b){
 a = find(a);
 b = find(b);
 if(a == b) return;
 par[a] = b;
}
 
int n, q, a[N+1];
struct ele{
 int l, r, c;
};
ele v[N+1];
 
void solve(){
 cin >> n >> q;
 For(i,1,q){
  cin >> v[i].l >> v[i].r >> v[i].c;
 }     
 
 For(i,1,q){
  int l = v[i].l;
  int r = v[i].r;
  int c = v[i].c;
 
  while(1 + 1 == 2){
   // cout << l << " ";
   l = find(l);
   if(l > r) break;
   if(l != c){
    a[l] = c;
    if(a[l-1]) Union(l-1, l);
    Union(l, l+1);
   }
   ++l;
  }
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