/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
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
 
int powmod(int a, int b){
 int ans = 1;
 while(b){
  if(b&1) ans = ans * a;
  a = a * a;
  b >>= 1;
 }
 return ans;
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  int ans = n*(n+1)/2;
  
  int sum = 0, i = 0;
  while(powmod(2, i) <= n){
   sum += powmod(2, i);
   ++i;
  }
  
  cout << ans - 2 * sum << "\n";
 }
 
 return 0;
}