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
const int N = 1e7 + 5;
 
int p[N+1];
void sieve(){
 for(int i=0;i<=N;i++) p[i] = i; 
 for(int i=2;i<=sqrt(N);i++){
  if(p[i] == i){
   for(int j=i;j<=N;j+=i){
    if(p[j] == j) p[j] = i;
   }
  }
 }
}
 
void solve(){
 int l, r; cin >> l >> r;
 if((l%2==0 || r%2==0) && l>=4){
  if(l%2==0) 
   cout << l/2 << ' ' << l/2 << "\n";
  else if(r%2 == 0) 
   cout << r/2 << ' ' << r/2 << "\n";
 }else if(r-l+1>=2){
  int x = ((r&1) ? r-1 : r);
  if(x/2 > 1) 
   cout << x/2 << ' ' << x/2 << "\n";
  else 
   cout << "-1\n";
 }else if(l==r){
  if(l%2==0){
   if(l/2 > 1) cout << l/2 << ' ' << l/2 << "\n";
   else cout << "-1\n";
  }else{
   if(p[l] == l) cout << "-1\n";
   else{
    int x = p[l];
    int t = l / x;
    if(t > 1) cout << x << ' ' << (t-1)*x << "\n";
    else cout << "-1\n";
   }
  }
 }else cout << "-1\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int bla = uniform_int_distribution<int>(1, 100)(rng);
    #define TASK ""
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    sieve();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}