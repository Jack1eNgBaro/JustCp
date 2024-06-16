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
 
int n, k; 
int a[N], b[N];
map<int,vector<ii>> mp;
 
int cmp(ii u, ii v){
    if(u.fi != v.fi) return u.fi < v.fi;
    return u.se < v.se;
}
 
void inp(){
    cin >> n >> k;
    For(i,1,n){
        char c; cin >> c;
        int x = c - '0';
        a[i] = x;
    }
    For(val,0,9){
        For(i,1,n){
            mp[val].pb({abs(a[i]-val), i});
        }
    }
}
 
vector<vector<int>> res;
void get(int trace){
    For(i,1,n) b[i] = a[i];
    map<int,vector<int>> vi;
    for(auto x: mp[trace]){
        vi[trace-a[x.se]].pb(x.se);
    }
    for(auto &it: vi){
        #define vec it.se
        if(it.fi > 0){
            sort(all(vec), greater<int>());
        }else{
            sort(all(vec));
        }
    }
    int cnt = vi[0].size();
    For(i,1,9){
        for(int it: vi[-i]){
            if(cnt < k){
                b[it] = trace;
                ++cnt;
            }
        }
        for(int it: vi[i]){
            if(cnt < k){
                b[it] = trace;
                ++cnt;
            }
        }
    }
    vector<int> tmp;
    For(i,1,n) tmp.pb(b[i]);
    res.pb(tmp);
}
 
void solve(){
    inp();
    int ans = 1e9, trace = -1;
    vector<int> ps;
    For(val, 0, 9){
        #define v mp[val]
        sort(v.begin(), v.end(), cmp);
        int sum = 0;
        For(i,0,k-1) sum += v[i].first;
        if(sum < ans){
            ans = sum;
            ps = {val};
        }else if(sum == ans){
            ps.pb(val);
        }
    }
    cout << ans << "\n";
    for(auto x: ps) get(x);
    sort(res.begin(), res.end());
    for(auto x: res[0]) cout << x;
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