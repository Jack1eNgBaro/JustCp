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
 
const int N = 20;
const int mod = 998244353;
 
int l, r, k;
int n, a[N];
ii dp[N][1024][2][2];
 
int powx(int b){
    int ans = 1, a = 10;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
 
//Dem - Tong
ii go(int pos, int mask, int zero, int flag, int val){
    if(pos > n){
        int cnt = __builtin_popcount(mask);
        if(cnt <= k) return {1, 0};
        else return {0, 0};
    }
    if(dp[pos][mask][zero][flag].fi != -1) return dp[pos][mask][zero][flag];
    
    int lim = 9;
    if(!flag) lim = a[pos];
    
    ii ans = {0, 0};
    For(i,0,lim){
        int new_mask = mask;
        if(!zero || (i!=0)) new_mask |= (1<<i);
        int new_val = (val*10+i)%mod;
        auto tmp = go(pos+1, new_mask, (zero&(i==0)), (i<lim||flag), new_val);
        
        ans.fi = (ans.fi + tmp.fi) % mod;
        if(ans.fi < 0) ans.fi += mod;
 
        int cnt = tmp.fi;
        int sum = i*(powx(n-pos)%mod*tmp.fi%mod)%mod;
        
        sum = (tmp.se + sum) % mod;
        if(sum < 0) sum += mod;
 
        ans.se = (ans.se + sum) % mod;
        if(ans.se < 0) ans.se += mod;
    }
    dp[pos][mask][zero][flag] = ans;
    return ans;
}
 
int cal(int s){
    string str = to_string(s);
    memset(dp, -1, sizeof(dp));   
    n = str.size();
    For(i,1,n) a[i] = str[i-1] - '0';
    auto res = go(1, 0, 1, 0, 0); 
    return res.se;
}
 
void solve(){
    cin >> l >> r >> k;
    int ans = cal(r) - cal(l-1);
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans;
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
    while(T--){
        solve();
    }
    return 0;
}