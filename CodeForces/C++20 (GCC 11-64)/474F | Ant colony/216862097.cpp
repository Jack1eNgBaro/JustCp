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
 
int n, q, a[N];
//Neu no la gcd thi tat ca cac doan co the chia het cho no=v?
unordered_map<int,vector<int>> mp;
int sg[4*N];
 
void build(int id, int l, int r){
    if(l == r) return sg[id] = a[l], void();
    int m = l + r >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    sg[id] = __gcd(sg[id << 1], sg[id << 1 | 1]);
}
 
int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return 0;
    if(l >= u && r <= v){
        return sg[id];
    }
    int m = l + r >> 1;
    return __gcd(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
 
void solve(){
    cin >> n;
    For(i,1,n){
        cin >> a[i];
        mp[a[i]].pb(i);
    }
    build(1, 1, n);
    cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        int x = get(1, 1, n, l, r);
        int ans = 0;
        if(mp.count(x)){
            auto i1 = upper_bound(all(mp[x]), r);
            auto i2 = lower_bound(all(mp[x]), l);
            ans = i1 - i2;
        }
        cout << r - l + 1 - ans << "\n";
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