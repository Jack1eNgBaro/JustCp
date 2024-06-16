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
 
int h, c, t;
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  cin >> h >> c >> t;
  if(t >= h) {cout << "1\n"; continue;};
  if(t <= (h + c) / 2){
   cout << "2\n"; continue;
  }
  
  int l = 1, r = (1LL<<40);
  int ans = 0;
  while(l <= r){
   int mid = (l + r) / 2;
   int sum = 1LL * mid * h + 1LL * (mid-1) * c;
   double x = (0.0000 + sum) / (0.0000 + mid + mid - 1);
   if(x >= t){
    ans = mid;
    l = mid + 1; 
   }else r = mid - 1;
  }
  
  int res = 2;
  double tb = (h + c) / 2;
  for(int mid=ans; mid <= ans+100;  mid++){
   int sum = 1LL * mid * h + 1LL * (mid-1) * c;
   double x = (0.0000 + sum) / (0.0000 + mid + mid - 1);
   if(abs(x - t) < abs(tb - t))
   {
    res = mid + mid - 1;
    tb = x;
   }
  }
  cout << res << "\n";
 }
 return 0;
}