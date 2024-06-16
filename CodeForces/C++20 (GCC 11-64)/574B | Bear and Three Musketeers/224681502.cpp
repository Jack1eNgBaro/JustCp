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
const int N = 1e6 + 5;
 
int n, m;
vector<int> adj[N];
vector<ii> vec;
 
int get_size(int u, int v, int x){
    return adj[u].size() - binary_search(all(adj[u]), v)
        - binary_search(all(adj[u]), x);
}
 
void solve(){
    cin >> n >> m;
    For(i,1,m){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        vec.pb({x, y});
    }    
    For(i,1,n) sort(all(adj[i]));
    int ans = 1e9;
    for(auto [u, v]: vec){
        vector<int> save;
        for(int x: adj[u]) if(binary_search(all(adj[v]), x)) save.pb(x);
 
        if(save.empty()) continue;
        for(auto x: save){
            int tmp = get_size(u, v, x)
                + get_size(v, u, x) + get_size(x, u, v);
            minimize(ans, tmp);
        }
    }
    if(ans == 1e9) ans = -1;
    cout << ans;
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