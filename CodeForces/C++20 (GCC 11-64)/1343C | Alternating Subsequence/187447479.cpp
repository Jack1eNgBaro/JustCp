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
  int n; cin >> n;
  int a[n + 1]; 
  for(int i=1;i<=n;i++) cin >> a[i];
  
  //0: am
  //1: duong
  int dp[n + 1][2];
  memset(dp, 0, sizeof(dp));
//  for(int i=1;i<=n+1;i++) dp[i][0] = dp[i][1] = 1;
 
  
  for(int i=1;i<=n;i++)
  {
   dp[i][0] = dp[i - 1][0];
   dp[i][1] = dp[i - 1][1];
   if(a[i] > 0){ 
    dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
   }else{
    dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
   }
  }  
  
  vector<int> v;
  for(int i=1;i<=n;i++){
   if(v.empty()){
    v.push_back(a[i]);
   }else{
    if(v.back() > 0){
     if(a[i] > 0) v.back() = max(v.back(), a[i]);
     else v.push_back(a[i]);
    }
    else{
     if(a[i] < 0) v.back() = max(v.back(), a[i]);
     else v.push_back(a[i]);
    }
   }
  }
  
  int mx = 0, s = 0;
  for(int i=1;i<=n;i++){
   mx = max(mx, max(dp[i][0], dp[i][1]));
  }
//  cout << mx << "\n";
  for(auto x: v){
//   cout << x << ' ';
   s += x;
  }
  cout << s << "\n";
 }
 return 0;
}