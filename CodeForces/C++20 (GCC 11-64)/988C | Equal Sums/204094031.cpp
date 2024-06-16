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
 map<int,vector<pii>> mp;
 
 int q; cin >> q;
 for(int c=1;c<=q;c++){
  int n; cin >> n;
  int a[n + 1], s = 0;
  for(int i=1;i<=n;i++){
   cin >> a[i];
   s += a[i];
  }
 
  set<int> se;
  for(int i=1;i<=n;i++){
   if(!se.count(s - a[i])){
    se.insert(s - a[i]);
    mp[s - a[i]].push_back({c, i});
   }
  }
 }
 
 for(auto it: mp){
  if(it.second.size() >= 2){
   cout << "YES\n";
   cout << it.second[0].first << ' ' << it.second[0].second << "\n";
   cout << it.second[1].first << ' ' << it.second[1].second << "\n";
   return 0;
  }
 } 
 cout << "NO\n";
 
 return 0;
}