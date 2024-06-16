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
 
int eq(char a, char b, char c){
    if(a == '.') return 0;
    if(b == '.') return 0;
    if(c == '.') return 0;
    return a == b && b == c;
}
 
void solve(){
    int tc; cin >> tc;
    while(tc--){
        string s[3];
        For(i,0,2) cin >> s[i];
        if(eq(s[0][0], s[1][1], s[2][2])) cout << s[0][0] << "\n";
        else if(eq(s[0][2], s[1][1], s[2][0])) cout << s[0][2] << "\n";
        
        else if(eq(s[0][0], s[0][1], s[0][2])) cout << s[0][0] << "\n";
        else if(eq(s[1][0], s[1][1], s[1][2])) cout << s[1][0] << "\n";
        else if(eq(s[2][0], s[2][1], s[2][2])) cout << s[2][0] << "\n";
 
        else if(eq(s[0][0], s[1][0], s[2][0])) cout << s[0][0] << "\n";
        else if(eq(s[0][1], s[1][1], s[2][1])) cout << s[0][1] << "\n";
        else if(eq(s[0][2], s[1][2], s[2][2])) cout << s[0][2] << "\n";
        else cout << "DRAW\n";
 
        // For(i,0,2) cout << s[i] << "\n";
 
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