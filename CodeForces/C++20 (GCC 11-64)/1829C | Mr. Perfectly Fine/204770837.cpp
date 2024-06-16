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
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  map<string,int> mp;
  int n; cin >> n;
  for(int i=0;i<n;i++){
   int x; cin >> x;
   string s; cin >> s;
   if(!mp.count(s)) mp[s] = x;
   else mp[s] = min(mp[s], x);
  }
  int x = 1e9, y = 1e9;
  if(mp.count("01") && mp.count("10")){
   x = mp["01"] + mp["10"];
  }
  if(mp.count("11")){
   y = mp["11"];
  }
  int ans = min(x, y);
  if(ans == 1e9) cout << "-1\n";
  else cout << ans << "\n";
 }
 return 0;
}