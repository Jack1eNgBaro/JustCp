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
const int N = 1e5 + 5;
 
void solve(){
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  int a[n+1];
  For(i,1,n) cin >> a[i];
 
  int pos1 = -1, pos2 = -1;
  for(int i=1;i+1<=n;i++){
   if(a[i] == 0 && a[i+1] == 1) pos1 = i;
  }
 
  if(a[1] == 1 || a[n] == 0 || pos1 != -1){
   if(a[1] == 1){
    cout << n + 1 << " ";
    For(i,1,n) cout << i << " ";
    cout << "\n";
   }
   else if(a[n] == 0){
    For(i,1,n+1) cout << i << " ";
    cout << "\n";
   }else if(pos1 != -1){
    For(i,1,pos1) cout << i << ' ';
    cout << n + 1 << " ";
    For(i,pos1+1,n) cout << i << " ";
    cout << "\n";
   }
  }else cout << "-1\n";
 
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