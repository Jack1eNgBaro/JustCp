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
const int N = 105;
 
int R, S, P;
double dp[N][N][N];
void solve(){
 cin >> R >> S >> P;
 dp[R][S][P] = 1;
 Fod(r, R, 0) Fod(s, S, 0) Fod(p, P, 0){
  if((r==0&&s==0) || (r==0&&p==0) || (s==0&&p==0)) continue;
  double total = r*s + s*p + p*r;
  if(r>0) dp[r-1][s][p] += dp[r][s][p]*(r*p/total);
  if(s>0) dp[r][s-1][p] += dp[r][s][p]*(s*r/total);
  if(p>0) dp[r][s][p-1] += dp[r][s][p]*(p*s/total);
  // cout << dp[r][s][p] << "\n";
 }
 double ans[3] = {0};
 For(i,0,R) ans[0] += dp[i][0][0];
 For(i,0,S) ans[1] += dp[0][i][0];
 For(i,0,P) ans[2] += dp[0][0][i];
 cout << fixed << setprecision(9) << ans[0] << " " << ans[1] << " " << ans[2];
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