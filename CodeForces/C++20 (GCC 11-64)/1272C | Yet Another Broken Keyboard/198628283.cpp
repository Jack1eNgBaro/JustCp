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
 
int n, k;
int ok[26], a[maxn+1], f[maxn+1];
main()
{
 file();
 cin >> n >> k;
 for(int i=1;i<=n;i++){
  char c; cin >> c;
  a[i] = c - 'a';
 }
 while(k--){
  char c; cin >> c;
  ok[c - 'a'] = 1;
 }
 
 int ans = 0;
 for(int i=1;i<=n;i++){
  if(!ok[a[i]]) f[i] = 0;
  else{
   f[i] = f[i - 1] + 1;
  }
  ans += f[i];
 }
 cout << ans;
 return 0;
}