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
 
int n, k, p, x, y;
vector<int> a, b;
 
void solve(){
 cin >> n >> k >> p >> x >> y;
 int sum = 0, suma = 0, sumb = 0;
 For(i,1,k){
  int val; cin >> val;
  sum += val;
  if(val < y){
   a.pb(val);
   suma += val;
  }
  else{
   b.pb(val);
   sumb += val;
  }
 }
 
 if(y == 1){
  if(n - k + sum > x) return cout << "-1", void();
  For(i, 1, n-k) cout << 1 << " "; return;
 }
 
 int sza = n/2 - a.size();
 int szb = n/2+1 - b.size();
 
 if(sum + (n-k) > x) return cout << "-1\n", void();
 if(sza + suma + sumb + szb*y > x) return cout << "-1\n", void();
 if(a.size() > n/2) return cout << "-1\n", void();
 
 // cout << a.size() << " " << b.size() << "\n";
 // cout << sza << " " << szb <<"\n";
 
 if(szb < 0) sza += szb;
 x -= sum; x -= sza;
 For(i,1,sza) cout << 1 << " ";
 For(i,1,szb) cout << y << " ";
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