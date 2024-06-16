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
 
int a[maxn + 1], f[maxn + 1];
map<int,set<int>> mp;
 
main()
{
 file();
 int n; cin >> n;
 mp[0].insert(0);
 for(int i=1;i<=n;i++){
  cin >> a[i];
  f[i] = f[i - 1] + a[i];
  mp[f[i]].insert(i);
 }
 
// int ans = 0;
// for(int i=1;i<=n;i++){
//  int j, x = f[i - 1];
//  auto it = mp[x].lower_bound(i);
//  if(it == mp[x].end()) 
//   j = n + 1;
//  else 
//   j = *it;
//  ans += j - i;
////  cout << i << ' ' << j << "\n";
// }
// cout << ans;
 
 int i = 0, j = 0, ans = 0;
 set<int> se;
 se.insert(0);
 while(i < n){
  while(j < n && !se.count(f[j + 1])){
   ++j; se.insert(f[j]);
  }
  ans += j - i;
  se.erase(f[i]);
  ++i;
 }
 cout << ans;
 return 0;
}