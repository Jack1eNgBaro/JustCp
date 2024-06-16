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
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  int n, k; cin >> n >> k;
  k = (k + n - 1) / k * k;
  
//  cout << n << "\n";
  
  int l = 1, r = 1e9;
  int ans = 1;
  while(l <= r){
   int m = (l + r) / 2;
   if(m * n < k){
    ans = m;
    l = m + 1;
   }else{
    r = m - 1;
   }
  }
  if(ans * n < k) ++ans;
  cout << ans << "\n";
 }
 return 0;
}