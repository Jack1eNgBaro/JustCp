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
 
int n, a[maxn + 1], b[maxn + 1];
int f[maxn + 1][3];
 
main()
{
 file();
 cin >> n;
 for(int i=1;i<=n;i++) cin >> a[i];
 for(int i=1;i<=n;i++) cin >> b[i];
 
 for(int i=0;i<=n;i++) f[i][0] = f[i][1] = f[i][2] = 1e9;
 
 
 for(int i=1;i<=n;i++)  f[i][0] = b[i];
 
 for(int i=2;i<=n;i++) 
 {
  for(int j=1;j<i;j++){
   if(a[i] > a[j]){
    f[i][1] = min(f[i][1], f[j][0] + b[i]);
   }
   
   if(i >= 3 && j >= 2){
    if(a[i] > a[j]){
     f[i][2] = min(f[i][2], f[j][1] + b[i]);
    }
   }
  }
 }
 
 int ans = 1e9;
 for(int i=3;i<=n;i++) ans = min(ans, f[i][2]);
 if(ans == 1e9) ans = -1;
 cout << ans;
 
 return 0;
}