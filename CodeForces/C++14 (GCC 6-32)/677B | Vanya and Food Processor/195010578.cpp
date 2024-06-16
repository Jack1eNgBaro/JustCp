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
const int maxn = 1e6;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int main()
{
 file();
 int n, h, k; cin >> n >> h >> k;
 int a[n + 1];  for(int i=1;i<=n;i++) cin >> a[i];
 
 ll i = 1, s = 0, ans = 0;
 while(i <= n){
  int j = i;
  while(j <= n && s + a[j] <= h){
   s += a[j]; ++j;
  }
  if(s >= k){
   ans += s / k; s %= k;
  }else{
   s = 0; ++ans;
  }
  i = j;
 }
 if(s == 0) return cout << ans, 0;
 if(s >= k) ans += s / k;
 else ++ans;
 cout << ans;
 return 0;
}