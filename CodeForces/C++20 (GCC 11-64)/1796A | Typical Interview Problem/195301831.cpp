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
 string as = "";
 for(int i=1;i<=1000;i++){
  if(i % 3 == 0 && i % 5 == 0) as += "FB";
  else if(i % 3 == 0) as += "F";
  else if(i % 5 == 0) as += "B";
 }
 
 int sz = as.size();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  string s; cin >> s;
  s = s;
  int ok = 0;
  for(int i=1;i+n-1<=sz;i++){
   int j = i + n - 1;
   string t(as.begin() + i, as.begin() + j + 1);
   if(t == s){
    ok = 1; break;
   }
  }
  if(ok) cout << "YES\n";
  else cout << "NO\n";
 }
 
 return 0;
}