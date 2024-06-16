#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
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
const int N = 2e5 + 5;
 
int n, Q, a[N];
 
class seg{
public:
    vector<int> sg;
    void resize(int n){
        sg = vector<int>(4*n, 0);
    }
    void build(int id, int l, int r){
        if(l == r){
            sg[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        sg[id] = (sg[id << 1] & sg[id << 1 | 1]);
    }
    int get(int id, int l, int r, int u, int v){
        if(l > v || r < u) return 1099511627775;
        if(l >= u && r <= v){
            return sg[id];
        }
        int m = l + r >> 1;
        int g1 = get(id << 1, l, m, u, v);
        int g2 = get(id << 1 | 1, m + 1, r, u, v);
        return (g1 & g2);
    }
};
seg segtree;
 
int kt(int L, int K, int mid){
    return segtree.get(1, 1, n, L, mid) >= K;
}
 
void solve(){
    cin >> n;
    For(i,1,n) cin >> a[i];
 
    segtree.resize(n);
    segtree.build(1, 1, n);
 
    // cout << segtree.get(1, 1, n, 1, 1) << "\n";
    // cout << segtree.get(1, 1, n, 1, 2) << "\n";
    // cout << segtree.get(1, 1, n, 1, 3) << "\n";
    // cout << segtree.get(1, 1, n, 1, 4) << "\n";
    // cout << segtree.get(1, 1, n, 1, 5) << "\n";
 
    cin >> Q;
    while(Q--){
        int L, K; cin >> L >> K;
        int left = L, right = n, ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(kt(L, K, mid)){
                ans = mid;
                left = mid + 1;
            }else right = mid - 1;
        }
        cout << ans << " ";
    }
    cout << "\n";
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