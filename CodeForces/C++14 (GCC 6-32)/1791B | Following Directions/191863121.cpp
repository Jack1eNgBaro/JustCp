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
 while(tc--)
 {
  int x = 0, y = 0;
  int n; cin >> n;
  int ok = 0;
  for(int i=1;i<=n;i++)
  {
   char c; cin >> c;
   if(c == 'U') ++x;
   else if(c == 'D') --x;
   else if(c == 'L') --y;
   else ++y;
   
   if(x == 1 && y == 1) ok = 1;
  }
  if(ok) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}