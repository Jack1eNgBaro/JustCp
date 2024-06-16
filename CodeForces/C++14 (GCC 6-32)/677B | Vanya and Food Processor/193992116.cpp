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
 
int n, h, k;
int a[maxn + 1];
main()
{
 file();
 cin >> n >> h >> k;
 for(int i=1;i<=n;i++) cin >> a[i];
 
 int ans = 0, s = 0;
 for(int i=1;i<=n;){
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
 if(s == 0){
  cout << ans; return 0;
 }
 if(s >= k) ans += s / k;
 else ++ans; 
 cout << ans;
 return 0;
}