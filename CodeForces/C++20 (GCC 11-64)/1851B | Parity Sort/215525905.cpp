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
const int N = 2e5 + 5;
 
int n, f[N];
void solve(){
    memset(f, 0, sizeof(f));
    priority_queue<int, vector<int>, greater<int>> a, b;
    cin >> n;
    For(i,1,n){
        int x; cin >> x;
        f[i] = (x & 1);
        if(x&1) a.push(x);
        else b.push(x);
    }
    For(i,1,n){
        if(f[i] == 0) f[i] = b.top(), b.pop();
        else f[i] = a.top(), a.pop();
    }
    int mx = f[1];
    For(i,2,n){
        if(f[i] < mx) return cout << "NO\n", void();
        mx = max(mx, f[i]);
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