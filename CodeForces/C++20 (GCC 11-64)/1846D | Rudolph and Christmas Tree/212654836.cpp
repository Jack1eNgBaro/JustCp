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
 
struct ele{
    int s, t;
};
 
void solve(){
    int tc; cin >> tc;
    while(tc--){
        int n, d, h; cin >> n >> d >> h;
        int b[n+1];
        For(i,1,n) cin >> b[i];
 
        ele a[n];
        For(i,1,n){
            int x = b[i];
            if(i == n) a[i] = {x, x + h};
            else{
                a[i] = {x, min(x + h, b[i + 1])};
            }
        }
        double ans = 0;
        For(i,1,n){
            if(i < n){
                if(a[i].t - a[i].s == h){
                    ans += 0.5 * h * d;
                }else{
                    double h1 = (a[i].t - a[i].s);
                    double h2 = (h - h1);
                    double x = 1.0*d/(2+2*h2/h1);
                    ans += 1.0*h1*d - 1.0*h1*x;
                }
            }
            else{
                ans += 0.5 * h * d;
            }
        }
        cout << fixed << setprecision(7) << ans << '\n';
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