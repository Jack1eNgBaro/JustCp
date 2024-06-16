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
  vector<int> a(4);
  for(int i=0;i<4;i++){
   char c; cin >> c;
   a[i] = c - '0';
  }
  map<int,int> mp;
  for(int x: a) mp[x]++;
  
  int mx = 0;
  for(auto x: mp){
   if(x.second > mx){
    mx = x.second;
   }
  }  
  
  int s = 0;
  for(auto x: mp) s += x.second;
  if(mp.size() == 1) cout << "-1\n";  
  else if((s-mx)+1>=mx) cout << s << "\n";
  else{
   int x = s - mx;
   int y = mx - (x+1);
   cout << s + y + 1<< "\n";
  }
 }
 
 return 0;
}