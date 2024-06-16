/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  vector<int> v;
  int ok = 0;
  
  if(n % 2 == 0){
   cout << "-1\n"; continue;
  }
  
  while(n != 1){
   int x = n / 2;
   if(x&1){
    v.push_back(2);
    n = n / 2;
   }
   else{
    v.push_back(1);
    n = n / 2 + 1;
   }
  }
  cout << v.size() << "\n";
  reverse(v.begin(), v.end());
  for(auto x: v) cout << x << ' '; cout << '\n';
 }
 
 return 0;
}