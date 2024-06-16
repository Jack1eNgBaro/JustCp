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
 
int n;
unordered_map<int,string> x;
unordered_map<int,string> y;
 
void cal(int n){
   if(n == 0) cout << "zero";
   else if(n < 10) cout << y[n];
   else if(n == 10) cout << "ten";
   else if(n == 11) cout << "eleven";
   else if(n == 12) cout << "twelve";
   else if(n == 14) cout << "fourteen";
   else if(n <= 19){
     int b = n%10;
     cout << x[b] << "teen"; 
   }else{
     int b = n%10;
     int a = n/10;
     cout << x[a] + "ty";
     if(b != 0) cout << "-" << y[b];
   }
}
 
void solve(){
    cin >> n;
    y[0] = "";
    y[1] = "one"; y[2] = "two";   y[3] = "three";
    y[4] = "four";  y[5] = "five";  y[6] = "six";
    y[7] = "seven"; y[8] = "eight"; y[9] = "nine";
 
    x[1] = "one"; x[2] = "twen";   x[3] = "thir";
    x[4] = "for";  x[5] = "fif";  x[6] = "six";
    x[7] = "seven"; x[8] = "eigh"; x[9] = "nine";
 
    cal(n);
 
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