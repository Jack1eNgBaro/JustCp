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
 
main()
{
 file();
 cin >> n;
 for(int i=1;i<=n;i++) cin >> a[i];
 for(int i=1;i<=n;i++) cin >> b[i];
 
 int ans = 0, cnt = 0;
 map<long double, int> mp;
 for(int i=1;i<=n;i++){
  if(a[i] == 0 && b[i] == 0) cnt++;
  if(a[i] != 0){
   long double x = (long double)(b[i]) / a[i];
   mp[x]++;
   ans = max(ans, mp[x]);
  }
 }
 
 cout << ans + cnt;
 return 0;
}