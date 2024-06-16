#include<bits/stdc++.h>
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
 
int v[N];
void solve(){
    multiset<int> ms;
    int n; cin >> n;
    vector<int> a, b;
    For(i,1,n){
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    For(i,1,n){
        if(i<=n/2) a.pb(v[i]);
        else b.pb(v[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    // for(auto x: a) cout << x << ' '; cout << '\n';
    // for(auto x: b) cout << x << ' '; cout << '\n';
 
    int i = 0, j = 0, ans = 0;
    while(i < a.size() && j < b.size()){
        if(2*a[i] <= b[j]){
            ++i; ++j; 
            ++ans;
        }else if(2*a[i] > b[j]){
            ++j; ++ans;
        }
    }
    ans += a.size() - i;
    ans += b.size() - j;
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