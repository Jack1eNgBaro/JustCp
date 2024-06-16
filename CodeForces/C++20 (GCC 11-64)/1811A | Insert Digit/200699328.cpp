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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = "~" + s;
 
  int ok = 0;
  for(int i=1;i<=n;i++){
   int x = s[i] - '0';
   char tmp = k + '0';
   string t; t += tmp;
   if(k > x){
    s.insert(i, t);
    ok = 1;
    break;    
   }
  }  
  char tmp = k + '0';
  string t; t += tmp;
  if(!ok) s.insert(n+1, t);
  s.erase(s.begin()); cout << s << "\n";
    
 }
 
 return 0;
}