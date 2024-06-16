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
 
int a[N];
void solve(){
    int n; cin >> n;
    For(i,1,n-1) cin >> a[i];
 
    if(a[n-1] > n*(n+1)/2) return cout << "NO\n", void();
 
    set<int> se;
    For(i,1,n) se.insert(i);
 
    multiset<int> ms;
 
    if(a[1] <= n) se.erase(a[1]);
    else{
        ms.insert(a[1]);
    }
    For(i,2,n-1){
        int x = a[i] - a[i-1];
        if(x > n){
            ms.insert(x);
        }else{
            if(se.count(x)) se.erase(x);
            else ms.insert(x);
        }
    }
 
    // for(auto x: ms) cout << x << " "; cout << " - ";    for(auto x: se) cout << x << ' '; cout << "\n";
    if(ms.size() >= 2) 
            return cout << "NO\n", void();
    if(ms.size() == 0) 
            return cout << "YES\n", void();
    if(ms.size() == 1){
        int t = *ms.begin();
        int sum = 0;
        for(auto x: se) sum += x;
        if(sum == t) cout << "YES\n";
        else cout << "NO\n";
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
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}