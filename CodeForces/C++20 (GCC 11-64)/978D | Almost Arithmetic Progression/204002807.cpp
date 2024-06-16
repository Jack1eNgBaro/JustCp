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
 
const int maxn = 1e6;
const int mod = 1e9 + 7;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, a[maxn + 1];
 
int test(int d, int cur, int ans){
 for(int i=3;i<=n;i++){
  int ok = 0;
  for(int j=-1;j<=1;j++){
   if(a[i] + j == cur){
    ans += abs(j);
    ok = 1;
    break;
   }    
  }
  if(!ok){
   return 1e9;
  }
  cur = cur + d;
 }
 return ans;
}
 
main()
{
 file(); 
 cin >> n;
 if(n <= 2) return cout << "0", 0;
 for(int i=1;i<=n;i++) cin >> a[i];
 
 int res = 1e9;
 for(int u=-1;u<=1;u++) for(int v=-1;v<=1;v++){
  int x = a[1] + u;
  int y = a[2] + v;
  int d = y - x;
  
  int ans = abs(u) + abs(v);
  int cur = y + d; 
  res = min(res, test(d, cur, ans));
 }
 if(res == 1e9) res = -1;
 cout << res;
 return 0;
}