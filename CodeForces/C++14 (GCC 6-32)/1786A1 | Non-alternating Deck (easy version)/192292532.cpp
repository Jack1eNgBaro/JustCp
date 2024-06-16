#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  int a = 0, b = 0, c = 1;
  for(int i=1;i<=n;i++){
   ++c;
   if((i % 4) == 0 || (i % 4) == 1){
    if(n >= i){
     a += i; n -= i;
    }else{
     a += n; break;
    }
   }
   else if(i % 4 == 2 || i % 4 == 3){
    if(n >= i){
     b += i; n -= i;
    }else{
     b += n; break;
    }
   }
  }
  if(c % 4 == 0 || c % 4 == 1) a += n;
  else b += n;
  cout <<a  << ' ' << b << "\n";
 }
 return 0;
}