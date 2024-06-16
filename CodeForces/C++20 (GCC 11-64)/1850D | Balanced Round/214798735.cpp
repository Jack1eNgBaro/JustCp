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
const int N = 1e6 + 5;
 
int a[N], f[N], g[N];
void solve(){
    int tc; cin >> tc;
    while(tc--){
        int n, k; cin >> n >> k;
        For(i,1,n) cin >> a[i];
        sort(a + 1, a + n + 1);
 
        f[1] = 1;
        For(i,2,n) f[i] = ((a[i]-a[i-1] <= k) ? f[i-1] : i);
        g[n] = n;
        Fod(i,n-1,1) g[i] = ((a[i+1]-a[i] <= k) ? g[i + 1] : i);
 
        // For(i,1,n) cout << f[i] << ' '; cout << "\n";
        // For(i,1,n) cout << g[i] << ' '; cout << "\n";
 
        int ans = 1e9;
        For(i,1,n){
            minimize(ans, n - (g[i] - f[i] + 1));
        }
        cout << ans << "\n";
 
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