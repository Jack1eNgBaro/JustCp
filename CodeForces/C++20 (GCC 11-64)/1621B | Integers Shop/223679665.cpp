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
 
int n;
struct Node{
    int val, cost, id;
};
 
void minisol(){
    ii best = {-1, -1};
    Node a, b;
 
    cin >> n;
    For(i,1,n){
        int x, y, c;
        cin >> x >> y >> c;
 
        if(i == 1){
            best = {y-x+1, c};
            a = {x, c, 1};
            b = {y, c, 1};
        }else{
             //best
            int cur_len = y-x+1;
            if(cur_len > best.fi) best = {y-x+1, c};
            else if(cur_len == best.fi){
                minimize(best.se, c);
            }
 
            //min
            if(x < a.val){
                a = {x, c, i};
            }else if(x == a.val){
                if(c < a.cost){
                    a.cost = c;
                    a.id = i;
                }
            }
 
            //max
            if(y > b.val){
                b = {y, c, i};
            }else if(y == b.val){
                if(c < b.cost){
                    b.cost = c;
                    b.id = i;
                }
            }
        }
 
        int opt1 = (b.val - a.val + 1);
        int opt2 = best.fi;
 
        if(opt1 > opt2){
            int ans = a.cost + b.cost;
            if(a.id == b.id) ans -= a.cost;
            cout << ans << "\n";
        }else if(opt1 < opt2){
            cout << best.se << "\n";
        }else{
            int ans = a.cost + b.cost;
            if(a.id == b.id) ans -= a.cost;
            cout << min(ans, best.se) << "\n";
        }
    }
}
 
void solve(){
    minisol();
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