#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
 
string s, a[15];
int n, k, dp[105];
pii trace[105]; // trace luu {thu tu, vi tri}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--)
 {
  cin >> s >> k;
  s = "~" + s;
  for(int i=1;i<=k;i++) cin >> a[i];
  for(int i=1;i<s.length();i++) dp[i] = 1e9, trace[i] = {-1, -1};
  
  for(int i=1;i<s.length();i++)
   for(int j=1;j<=k;j++)
    // cat xau tu i -> i + a[j].length() || i - > s.end()
     if(s.substr(i, min(a[j].length(), s.length() - i + 1)) == a[j])
     for(int p=i;p<=i+a[j].length()-1;p++) if(dp[p] > dp[i - 1] + 1)
     {
      dp[p] = dp[i - 1] + 1;
      trace[p] = {j - 1, i - 1};       
     }
  if(dp[s.length() - 1] != 1e9){
   cout << dp[s.length()-1] << "\n";
   int x = s.length() - 1;
   while(x != 0)
   {
    cout << trace[x].first + 1 << ' ' << trace[x].second + 1 << "\n";
    x = trace[x].second;
   }
  }
  else{
   cout << -1 << "\n";
  }
 }
   
 return 0;
}