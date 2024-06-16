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
  int l, r, x; cin >> l >> r >> x;
  int a, b; cin >> a >> b;
 
  if(a == b){
   cout << "0\n"; continue;
  }else if(abs(b - a) >= x){
   cout << "1\n"; continue;
  }
 
  int ok = 1;
  if(abs(l - a) < x && abs(r - a) < x) ok = 0;
  if(abs(l - b) < x && abs(r - b) < x) ok = 0;
  
  if(ok == 0) cout << "-1\n";
  else
  {
   int ans = 1e9;
   if(abs(l - a) >= x){
    if(abs(l - b) >= x) ans = min(ans, 2);
    else ans = min(ans, 3);
   }
   
   if(abs(r - a) >= x){
    if(abs(r - b) >= x) ans = min(ans, 2);
    else ans = min(ans, 3);
   }
   
   cout << ans << "\n";
  }
  
 }
 return 0;
}