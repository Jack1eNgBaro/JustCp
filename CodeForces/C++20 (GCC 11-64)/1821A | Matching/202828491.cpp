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
  if(s[0] == '0'){
   cout << "0\n"; continue;
  }
  int ans = 1, ok = 0;
  int sz = s.size();
  for(int i=sz-1;i>=0;i--){
   if(s[i] == '?'){
    ok = 1;
    if(i != 0) ans *= 10;
    else ans *= 9;
   }
  }
  cout << ans << "\n";
 }
 
 return 0;
}