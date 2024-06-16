#include<bits/stdc++.h>
using namespace std;
 
int encode(string s){
 int ans = 0;
 for(char ch: s){
  int c = ch - 'a';
  ans += (1 <<c);
 }return ans;
}
 
int main()
{
 int n; cin >> n;
 int f[n + 1][8];
 for(int i=0;i<=n;i++) for(int j=0;j<8;j++) f[i][j] = 1e9;
 f[0][0] = 0;
 for(int i=0;i<n;i++)
 {
  int w; string s; cin >> w >> s;
  int x = encode(s);
  for(int j=0;j<8;j++){
   f[i + 1][j] = min(f[i + 1][j], f[i][j]);
   f[i + 1][j | x] = min(f[i + 1][j | x], f[i][j] + w);
  }
 }
 int ans = f[n][7];
 cout << (ans == 1e9 ? -1 : ans);
 return 0;
}