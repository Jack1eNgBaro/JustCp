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
const int N = 5005;
 
string s;
int dp[N][N];
 
int get(int x, int y, int u, int v){
    int ans = dp[u][v] - dp[u][y-1] - dp[x-1][v] + dp[x-1][y-1];
    return ans;
}
 
void solve(){
    cin >> s;
    int n = s.size();
    s = "~" + s;
    For(i,1,n) dp[i][i] = 1;
    For(len,2,n){
        for(int i=1;i+len-1<=n;i++){
            int j = i + len - 1;
            if(len == 2) dp[i][j] = (s[i] == s[j]);
            else{
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] == 1);
            }
        }
    }
    For(i,1,n)  For(j,1,n)  dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << get(l, l, r, r) << "\n";
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