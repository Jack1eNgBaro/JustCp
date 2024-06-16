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
const int block = 500; 
 
int n, m, a[N];
map<int,int> mp[block];
 
int trau(int l, int r, int val){
 For(i,l,r){
  if(a[i] != val) return i;
 }
 return -1;
}
 
int get(int l, int r, int val){
 int blockL = l/block + 1;
 int blockR = r/block - 1;
 if(blockL >= blockR){
  return trau(l, r, val);
 }
 int ans = -1;
 For(i,blockL,blockR){
  auto i1 = *mp[i].begin();
  auto i2 = *mp[i].rbegin();
  if(i1.fi == i2.fi && i1.fi == val) continue;
  else if(i1.fi == val) ans = max(ans, i2.se);
  else if(i2.fi == val) ans = max(ans, i1.se);
 }
 ans = max(trau(l,blockL*block-1,val), ans);
 ans = max(trau((blockR+1)*block,r,val), ans);
 return ans;
}
 
void solve(){
    cin >> n >> m;
    int sz = n / block + 1;
    for(int i=0;i<n;i++){
     cin >> a[i];
     mp[i/block][a[i]] = i;
    }
    while(m--){
     int l, r, x; cin >> l >> r >> x;
     --l; --r;
     int t = get(l, r, x);
     if(t == -1) cout << t << "\n";
     else cout << t + 1 << '\n';
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