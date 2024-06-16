#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
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
const int N = 1e6 + 5;
 
int n, q, a[N], sg[4*N], lz[4*N];
 
void build(int id, int l, int r){
    if(l == r) return sg[id] = a[l], void();
    int m = l + r >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    sg[id] = min(sg[id << 1], sg[id << 1 | 1]);
}
 
void down(int id){
    sg[id << 1] += lz[id];
    sg[id << 1 | 1] += lz[id];
 
    lz[id << 1] += lz[id];
    lz[id << 1 | 1] += lz[id];
 
    lz[id] = 0;
}
 
void update(int id, int l, int r, int u, int v, int val){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        sg[id] += val;
        lz[id] += val;
        return;
    }
    down(id);
    int m = l + r >> 1;
    update(id << 1, l, m, u, v, val);
    update(id << 1 | 1, m + 1, r, u, v, val);
    sg[id] = min(sg[id << 1], sg[id << 1 | 1]);
}
 
int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return 1e9;
    if(l >= u && r <= v){
        return sg[id];
    }
    down(id);
    int m = l + r >> 1;
    int g1 = get(id << 1, l, m, u, v);
    int g2 = get(id << 1 | 1, m + 1, r, u, v);
    return min(g1, g2);
}
 
void solve(){
    cin >> n;
    For(i,1,n) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    cin.ignore();
    while(q--){
        string s, t; 
        getline(cin, s);
        stringstream ss(s);
        
        vector<int> v;
        while(ss >> t) v.pb(stoi(t));
 
        ++v[0];
        ++v[1];
 
        if(v.size() == 2){
            if(v[0] <= v[1]) cout << get(1, 1, n, v[0], v[1]) << "\n";
            else{
                int t1 = get(1, 1, n, v[0], n);
                int t2 = get(1, 1, n, 1, v[1]);
                cout << min(t1, t2) << "\n";
            }
        }
        else{
            if(v[0] <= v[1]) update(1, 1, n, v[0], v[1], v[2]);
            else{
                update(1, 1, n, v[0], n, v[2]);
                update(1, 1, n, 1, v[1], v[2]);
            }
        }
 
    }
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