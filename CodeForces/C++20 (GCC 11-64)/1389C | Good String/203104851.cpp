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
 int tc; cin >> tc;
 while(tc--){
  string s; cin >> s;
  int n = s.size();
  s = "~" + s;
  
  map<int,vector<int>> mp;
  for(int i=1;i<=n;i++){
   mp[s[i]-'0'].push_back(i);
  }
  
//  for(auto x: mp){
//   cout << x.first << ": ";
//   for(auto t: x.second) cout << t << ' ';
//   cout << "\n";
//  }
  
  int ans = n;
  for(int i=0;i<=9;i++) ans = min(ans, n - (int)mp[i].size());
  
  for(int x=0;x<=9;x++){
   for(int y=0;y<=9;y++){
    if(x == y) continue;
    vector<int> a = mp[x], b = mp[y];
    int i = 0, j = 0, c = 0, lasty = 0;
    while(i < (int)a.size() && j < (int)b.size()){
     while(i < a.size() && a[i] < lasty) ++i;
     if(i == a.size()) break;
     if(a[i] < b[j]){
      c += 2;
      lasty = b[j];
      ++i; ++j;      
     }else{
      ++j;
     }
    }
    ans = min(ans, n - c);
   }
  }
  cout << ans << "\n";
 }
 
 return 0;
}