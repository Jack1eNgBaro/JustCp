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
 
int a[maxn + 1], cnt[maxn + 1];
main()
{
 file();
 int n; cin >> n;
 int s = 0;
 for(int i=1;i<=n;i++){
  cin >> a[i]; s += a[i];
 }
 
 if((s % 3) != 0) return cout << 0, 0;
 s /= 3;
 
 int sum = 0;
 for(int i=n;i>=1;i--){
  sum += a[i]; 
  cnt[i] = cnt[i + 1];
  if(sum == s) cnt[i]++;
 }
 
 int ans = 0; sum = 0;
 for(int i=1;i<=n;i++){
  sum += a[i];
  if(sum == s){
   ans += cnt[i + 2];
  }
 }
 cout << ans;
 return 0;
}