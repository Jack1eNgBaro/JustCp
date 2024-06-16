#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#define MOD 1000000007
#define fi first
#define se second
#define int unsigned long long
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
 
int n, k, a[N], dp[N][55];
 
int bit[N];
void add(int id, int x){
    id += 5;
    while(id <= N){
        bit[id] = (bit[id] + x);
        id += id & (-id);
    }
}
 
int get(int id){
    id += 5;
    int ans = 0;
    while(id >= 1){
        ans = (ans + bit[id]);
        id -= id & (-id);
    }
    return ans;
}
 
void solve(){
    cin >> n >> k;
    For(i,1,n) cin >> a[i];
    ++k;
 
    For(i,1,n) dp[i][1] = 1;
    For(sz,2,k){
        memset(bit, 0, sizeof(bit));
        For(i,1,n){
            dp[i][sz] = get(a[i]-1);
            add(a[i], dp[i][sz-1]);
        }
    }
 
    // For(sz,1,k){
    //     For(i,1,n) cout << dp[i][sz] << " ";
    //     cout << "\n";
    // }
    int res = 0;
    For(i,1,n) res = (res + dp[i][k]);
    cout << res;
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
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}