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
 int n, t; cin >> n >> t;
 if(n <= 18){
  int bs = pow(10, n - 1);
  int ans = (bs + t - 1) / t * t;
  if(ans >= pow(10, n)) ans = -1;
  cout << ans;
 }else{
  int bs = pow(10, 17);
  int ans = (bs + t - 1) / t * t;
  int thieu = n - 18;
  cout << ans;
  while(thieu--) cout << 0;
 }
 return 0;
}