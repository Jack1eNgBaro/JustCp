#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 int n; cin >> n;
 int a[n]; for(int &i: a) cin >> i;
 
 int dp[n][3];
 for(int i=0;i<n;i++) dp[i][0] = dp[i][1] = dp[i][2] = 1e9;
 
 dp[0][0] = 1;
 if(a[0] == 1 || a[0] == 3) dp[0][1] = 0;
 if(a[0] == 2 || a[0] == 3) dp[0][2] = 0;
 
 for(int i=1;i<n;i++)
 {
  dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
  
  if(a[i] == 1 || a[i] == 3)
   dp[i][1] = min({dp[i - 1][0], dp[i - 1][2]});
   
  if(a[i] == 2 || a[i] == 3)
   dp[i][2] = min({dp[i - 1][1], dp[i - 1][0]});
  
 }
 cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
 return 0;
}