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
const int N = 1e5 + 5;
 
int n, p, k, x, y;
int s = 0;
int c1 = 0, c2 = 0, s1 = 0, s2 = 0;
 
void solve(){
    cin >> n >> k >> p >> x >> y;
    For(i,1,k){
     int x; cin >> x;
     if(x < y){
      c1++; s1 += x;
     }else{
      c2++; s2 += x;
     }
     s += x;
    }
 
    c1 = n/2-c1;
    c2 = n/2+1-c2;
 
    if(y == 1){
     if(n-k+s > x) return cout << "-1\n", void();
     s = x - s;
     For(i,1,n-k) cout << 1 << ' ';
     return;
    }
    if(c2<0) c1 += c2;
    if(s + (n-k) > x || s1 + c1 + s2+c2*y > x || c1 < 0) 
     return cout << "-1\n", void();
 
    s = x - s;
    For(i,1,c1) cout << 1 << " ";
    For(i,1,c2) cout << y << " ";
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