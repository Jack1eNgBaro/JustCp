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
  int c = 1;
  int a0 = 0, a1 = 0;
  int b0 = 0, b1 = 0;
  for(int i=1;i<=n;i++){
   ++c;
   if((i % 4) == 0 || (i % 4) == 1){
    if(n >= i){
     int x = (i + 1) / 2;
     int y = i - x;
     a0 += x; a1 += y;
     n -= i;
    }else{
     int x = (i + 1) / 2;
     a0 += x; a1 += n;
     break;
    }
   }
   else if(i % 4 == 2 || i % 4 == 3){
    if(n >= i){
     int x = (i + 1) / 2;
     int y = i - x;
     b1 += x; b0 += y;
     n -= i;
    }else{
     int x = (i + 1) / 2;
     b1 += x; b0 += n;
     break;
    }
   }
  }
  if(c % 4 == 0 || c % 4 == 1){
   int x = (n + 1) / 2;
   a0 += x; a1 += (n - x);
  }else{
   int x = (n + 1) / 2;
   b1 += x; b0 += (n - x);
  }
  cout << a0 << ' ' << a1 << ' ' << b0 << ' ' << b1 << "\n";
 }
 return 0;
}