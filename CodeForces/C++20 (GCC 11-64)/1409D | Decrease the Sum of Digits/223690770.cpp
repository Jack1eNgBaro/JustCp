#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
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
 
int sumdig(int n){
    int ans = 0;
    while(n){
        ans += (n%10); n/= 10;
    }
    return ans;
}
 
//khi them 1 dv vao so hien tai thi tcs chi co the tang len 
//206(8) -> 207(9) -> 208(10) -> 209(11) 
//nhung ma chi khi them ((10 - (n%10)) % 10) thi cs cuoi = 0 gia tri giam
//210(3)
 
int f[N], g[N];
void solve(){
    int tc; cin >> tc;
    while(tc--){
        int n, k; cin >> n >> k;
        if(sumdig(n) <= k){
            cout << "0\n"; continue;
        }
 
        int ans = 0;
        int pw = 1; //power of 10
        For(i,0,18){
            //i bit tu ben phai
            int r = (n / pw) % 10;      
            //set bit thu i ve 0, de dat gia tri be hon
            int add = ((10 - r) % 10) * pw; 
            n += add;
            ans += add;
            if(sumdig(n) <= k){
                break;
            }
            //ve ben trai 1 bit *= 10
            pw *= 10;
        }
        cout << ans << "\n";
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
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}