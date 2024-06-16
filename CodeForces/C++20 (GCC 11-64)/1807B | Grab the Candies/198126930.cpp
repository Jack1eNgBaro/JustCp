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
  int n; cin >> n;
  int a[n]; for(int &i: a) cin >> i;
  
  int m = 0, b = 0;
  for(int x: a){
   if(x&1) b += x;
   else m += x;
  }
  
  cout << ((m > b) ? "YES\n" : "NO\n"); 
 }
 
 return 0;
}