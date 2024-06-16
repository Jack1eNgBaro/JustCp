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
 multiset<string> ms;
 ms.insert("Ye");
 ms.insert("es");
 ms.insert("sY");
 while(tc--)
 {
  string s; cin >> s;
  int n = s.size(), ok = 1;
  
  if(n == 1){
   if(s == "Y" || s == "e" || s == "s") 
    ok = 1;
   else 
    ok = 0;
  }
  else{
   for(int i=0;i<n-1;i++)
   {
    string t = "";
    t = t + s[i] + s[i + 1];
    if(ms.count(t) == 0){
     ok = 0; break;
    }
   }
  }
  
  if(ok) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}