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
const int N = 2e5 + 5;
 
int n, used[N];
map<int,vector<int>> adj;
 
int dfs(int u){
 used[u] = 1;
 for(int v: adj[u]){
  if(used[v]) continue;
  return dfs(v) + 1;
 }
 return 1;
}
 
//can chia 2n so ra thanh 2 tap, moi tap co n so rieng biet
//=>> moi so xh trong 1 tap 1 lan
void solve(){
 adj.clear();
 memset(used, 0, sizeof(used));
 
    cin >> n;
    int dbrr = 0;
    For(i,1,n){
     int x, y; cin >> x >> y;
     adj[x].pb(y);
     adj[y].pb(x);
 
     if(x == y ||  //Domino co x=y thi cho vao tap nao cx fail
      adj[x].size() > 2 || adj[y].size() > 2)  //x hoac y xuat hien nhieu hon 2 lan thi fail)
     dbrr = 1;
    }
    For(i,1,n){
     if(used[i] == 0 && dfs(i) % 2){
      dbrr = 1;
     }
    }
    if(dbrr){
     return cout << "NO\n", void();
    }
    cout << "YES\n";
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
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
 