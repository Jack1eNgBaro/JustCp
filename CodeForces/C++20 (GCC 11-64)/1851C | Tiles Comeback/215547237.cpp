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
 
int n, k, a[N];
void solve(){
    cin >> n >> k;
    For(i,1,n) cin >> a[i];
    unordered_map<int,int> mp;
    if(k == 1) return cout << "YES\n", void();
    mp.clear();
    int en = -1;
    For(i,1,n){
        mp[a[i]]++;
        if(mp[a[1]] == k){
            en = i; break;
        }
    }
 
    mp.clear();
    int st = -1;
    Fod(i,n,1){
        mp[a[i]]++;
        if(mp[a[n]] == k){
            st = i; break;
        }
    }
 
    if(en == -1 || st == -1) return cout << "NO\n", void();
    if(a[1] == a[n]) return cout << "YES\n", void();
    if(en > st) cout << "NO\n";
    else{
        cout << "YES\n";
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
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}