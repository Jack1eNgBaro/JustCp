/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
#define fi first
#define se second
#define vi vector<int> 
 
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
 
int powf(int a, int b){
 int ans = 1;
 while(b){
  if(b&1) ans = ans * a;
  a *= a;
  b >>= 1;
 }
 return ans;
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, k; cin >> n >> k;
  if(k <= 31){
   int x = powf(2, k);
   if(n < x) cout << n + 1 << "\n";
   else cout << x << "\n";
  }else{
   cout << n + 1 << "\n";
  }
 }
 return 0;
}