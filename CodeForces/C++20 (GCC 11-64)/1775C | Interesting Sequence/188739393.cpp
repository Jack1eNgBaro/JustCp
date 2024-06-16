#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int calc(int a, int b){
 int cnt = 0;
 while(a != b && a > 0){
  a >>= 1;
  b >>= 1;
  ++cnt;
 }
 return (a << cnt);
}
 
main()
{
 file();
// int a, b; cin >> a >> b;
// cout << calc(a, b);
 int tc; cin >> tc;
 while(tc--)
 {
  int n, k; cin >> n >> k;
  int ans = -1, l = n, r = 5e18;
  
  while(l <= r)
  {
   int m = (l + r) / 2;
   int t = calc(n, m);
   if(t <= k){
    if(t == k) ans = m;
    r = m - 1;
   }
   else l = m + 1;
  }
  cout << ans << "\n";
 }
 return 0;
}