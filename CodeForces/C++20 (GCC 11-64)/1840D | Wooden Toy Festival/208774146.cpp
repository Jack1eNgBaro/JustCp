/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
#define fi first
#define se second
#define vi vector<int> 
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int kt(int a[], int n, int m){
 int cnt = 0, mx = 0;
 int l = 1, r = 1;
 while(r <= n){
  while(1+1==2){
   int x = (a[r] + a[l]) / 2;
   int y = max(x-a[l], a[r]-x);
   if(y>m) break;
   ++r;
  }
  ++cnt;
  l = r;
 }
 return cnt<=3;
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  int a[n + 1]; for(int i=1;i<=n;i++) cin >> a[i];
  sort(a + 1, a + n + 1);
 
   int l = 0, r = 1e9, ans = 0;
   while(l <= r){
    int m = (l + r) / 2;
    if(kt(a, n, m)){
     ans = m;
     r = m - 1;
    }else l = m + 1;
   }
   cout << ans << "\n";
 }
 return 0;
}