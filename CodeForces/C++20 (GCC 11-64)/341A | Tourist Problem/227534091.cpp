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
const int N = 1e7 + 5;
 
// ii bit[N];
// void add(int id, int x){
//  while(id <= 1e7){
//   bit[id].fi += x;
//   bit[id].se += 1;
//   id += id & (-id);
//  }
// }
// ii get(int id){
//  ii ans = {0, 0};
//  while(id >= 1){
//   ans.fi += bit[id].fi;
//   ans.se += bit[id].se;
//   id -= id & (-id);
//  }
//  return ans;
// }
 
// int gcd(int a, int b){
//  if(b == 0) return a;
//  return gcd(b, a % b);
// }
 
// void ngu(){
//     cin >> n;
//   gt[0] = 1;
//     int mx = 0;
//     For(i,1,n){
//      cin >> a[i];
//      maximize(mx, a[i]);
//      add(a[i], a[i]);
 
//      gt[i] = gt[i-1] * i;
//     }
 
//     int ans = 0, res = 1;
//     For(i,1,n){
//      auto t1 = get(mx);
//      auto t2 = get(a[i]);
 
//      ans += ((t1.fi - t2.fi) - a[i]*(t1.se - t2.se)) * (n - 1) * 2;
//     }
 
//     cout << ans << " " << res;
// }
 
const int sz = 1000005;
int n, a[sz], gt[sz];
 
int f[N], g[N];
 
void solve(){
 cin >> n;
 For(i,1,n) cin >> a[i];
 sort(a + 1, a + n + 1);
 
 For(i,1,n) f[i] = f[i-1] + a[i];
 Fod(i,n,1) g[i] = g[i+1] + a[i];
 
 //s1*(n-1)!
 // a[1] - 0 + a[2] - 0 + ...
 // moi con a[1] dung dau xuat hien trong (n-1)!
 //dat tong tren la s1 * (n-1)!
 int s1 = 0, s2 = 0;
 For(i,1,n) s1 += a[i]; 
 
 //Chon 2 thang a[i], a[i+1] ke nhau thi co (n-1) cach chon
 //con lai (n-2)! so cach chon cac so con lai
 //w = [a[i] * solg<i - tong<i + tong>i - a[i]*solg>i] (n-1) * (n-2)!
 //dat tong tren la s2 * (n-1)!
 For(i,1,n){
  // s2 += a[i] * i - f[i-1];
  s2 += g[i+1] - a[i] * (n - i);
  s2 += a[i] * (i-1) - f[i-1];
 }
 
 //Ket qua la
 //(s1 + s2) * (n-1)! / n! = (s1 + s2) / n;
 int ans = (s1 + s2);
 int t = gcd(ans, n);
 ans /= t;
 n /= t;
 
 cout << ans << ' ' << n << "\n";
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
    //cin >> T;s
    while(T--){
        solve();
    }
    return 0;
}