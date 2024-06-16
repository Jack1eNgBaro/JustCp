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
 
int n, q;
string str;
 
struct node{
    int ans, l, r;
}sg[4*N];
 
node add(node a, node b){
    node res;
    int x = min(a.l, b.r);
    res = {a.ans + b.ans + x, a.l + b.l - x, a.r + b.r - x};
    return res; 
}
 
void build(int id, int l, int r){
    if(l == r){
        if(str[l] == '(') sg[id] = {0, 1, 0};
        else sg[id] = {0, 0, 1};
        return;
    }
    int m = l + r >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    sg[id] = add(sg[id << 1], sg[id << 1 | 1]);
    // cout << l << ' ' << r << ' ' << sg[id].ans << " " << sg[id].l << ' ' << sg[id].r << "\n";
}
 
node get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return {0, 0, 0};
    if(l >= u && r <= v) return sg[id];
    int m = l + r >> 1;
    node n1 = get(id << 1, l, m, u, v);
    node n2 = get(id << 1 | 1, m + 1, r, u, v);
    return add(n1, n2);
}
 
void solve(){
    cin >> str;
    n = str.size();
    str = "~" + str;
    build(1, 1, n);
    cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cout << get(1, 1, n, x, y).ans * 2 << "\n";
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