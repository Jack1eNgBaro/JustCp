#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
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
 
int n, a[N], p[N];
vector<ii> vec;
 
void solve(){
    cin >> n;
    For(i,1,n) cin >> a[i];
 
    vec.pb({0, 0});
    memset(p, 0, sizeof(p));
 
    int Q; cin >> Q;
    For(id,1,Q){
        int type; cin >> type;
        if(type == 1){
            int pos, val; cin >> pos >> val;
            a[pos] = val;
            p[pos] = id;
        }else{
            int val; cin >> val;
            vec.pb({id, val});
        }
    }
 
    int sz = vec.size()-1;
    Fod(i,sz-1,0){
        maximize(vec[i].se, vec[i+1].se);
    }
 
    For(i,1,n){
        auto it = lower_bound(all(vec), make_pair(p[i], 0));
        if(it == vec.end()){
            cout << a[i] << ' ';
            continue;
        }
        int j = it - vec.begin();
        cout << max(a[i], vec[j].se) << " ";
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