/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
/*
ID: nbaro242
PROG: 
LANG: C++11
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
 string s; cin >> s;
 int n = s.size();
 s = "~" + s;
 for(int i=1;i<=n;i++){
  if(s[i] == '0' || s[i] == '8') return cout << "YES\n" << s[i] - '0',0;
 }
 if(n >= 2){
  for(int i=1;i<=n;i++){
   for(int j=i+1;j<=n;j++){
    int x = s[i] - '0';
    int y = s[j] - '0';
    int t = x*10+y;
    if(t % 8 == 0){
     cout << "YES\n";
     cout << x<<y;
     return 0;
    }
   }
  }
 }
 if(n >= 3){
  for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++){
   int x = s[i] - '0';
   int y = s[j] - '0';
   int z = s[k] - '0';
   int t = 100*x+10*y+z;
   if(t % 8 == 0){
    cout << "YES\n";
    cout << x<<y<<z;
    return 0;
   }
  }
 }
 cout << "NO\n";
 return 0;
}