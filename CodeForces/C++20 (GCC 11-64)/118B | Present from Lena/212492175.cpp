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
const int N = 100;
 
int a[N][N];
void solve(){
    int n; cin >> n;
    int m = 2*n + 1;
    memset(a, -1, sizeof(a));
    For(i,1,n+1){
        int j = n+1;
        int c = i-1;
        For(k,0,i){
            a[i][j-k] = a[i][j+k] 
            = a[m-i+1][j+k] = a[m-i+1][j-k] = c--;
        }
    }
    For(i,1,m){
        int x = i;
        if(x >= n + 1) x %= n + 1;
 
        For(j,1,m){
            if(a[i][j] >= 0){
                cout << a[i][j];
                if(j <= m && a[i][j+1] < 0) break;
                else cout << " ";
            }
            else cout << "  ";
        }
        cout << "\n";
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