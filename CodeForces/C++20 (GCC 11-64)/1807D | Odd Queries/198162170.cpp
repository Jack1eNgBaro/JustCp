/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 5005;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
void sol(){
 int n; cin >> n;
 int a[n + 1]; for(int i=1;i<=n;i++) cin >> a[i];
 sort(a + 1, a + n + 1);
 
 bitset<maxn> dp = {0};
 if(a[1] != 1) return cout << "NO\n", void();
 dp[0] = 1; 
 for(int i=1;i<=n;i++){
//  for(int i=0;i<=9;i++) cout << dp[i]; cout << "\n";
  dp |= (dp << a[i]);
  if(i < n && dp[a[i + 1]] == 0){
//   cout << "~" << a[i + 1];
   return cout << "NO\n", void();
  }
 }
 cout << "YES\n";
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  sol();    
 }
 return 0;
}