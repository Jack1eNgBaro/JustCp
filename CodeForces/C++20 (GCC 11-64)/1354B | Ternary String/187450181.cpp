#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
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
 int tc; cin >> tc;
 while(tc--)
 {
  string a; cin >> a;
  int n = a.size(); 
  a = "~" + a;
  
  int cnt = 0, ans = 1e9;
  map<char,int> mp;
  
  for(int l=1,i=1;i<=n;i++)
  {
   mp[a[i]]++;
   if(mp[a[i]] == 1) cnt++;
   while(cnt == 3){
    mp[a[l]]--;
    if(mp[a[l]] == 0) --cnt;
    ans = min(ans, i - l + 1);
    ++l;
   }
  }
  if(ans == 1e9) ans = 0;
  cout << ans << "\n";
 }
 return 0;
}