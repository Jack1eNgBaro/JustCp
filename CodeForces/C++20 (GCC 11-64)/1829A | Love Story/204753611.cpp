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
 string a = "codeforces";
 int tc; cin >> tc;
 while(tc--){
  string s; cin >> s;
  int ans = 0;
  for(int i=0;i<10;i++){
   if(s[i] != a[i]) ++ans;
  }
  cout << ans << "\n";
 }
 return 0;
}