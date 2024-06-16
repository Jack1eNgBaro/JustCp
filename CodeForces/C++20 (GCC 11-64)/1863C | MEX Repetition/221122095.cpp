/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;;
template <class X, class Y> bool minimize(X &a, Y b){
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b){
    if (a < b) return a = b, true;
    return false;
}
 
#define bit(x, i) ((x >> i) & 1)
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
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 31;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {return l + rng() % (r - l + 1);}
const int N = 1e5 + 5;
 
void solve(){
 int tc; cin >> tc;
 while(tc--){
  int n, k; cin >> n >> k;
  deque<int> dq;
  int cnt[n + 1];
  memset(cnt, 0, sizeof(cnt));
  For(i,1,n){
   int x; cin >> x;
   dq.pb(x);
   cnt[x] = 1;
  }
  int mex = -1;
  For(i,0,n){
   if(cnt[i] == 0){
    mex = i;
    break;
   }
  }
  dq.pb(mex);
  
  k %= (n + 1);
  while(k--){
   int tmp = dq.back(); dq.pop_back();
   dq.push_front(tmp);
  }
  For(i,0,n-1) cout << dq[i] << ' '; cout << "\n";
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