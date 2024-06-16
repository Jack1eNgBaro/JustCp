/*
  The only thing we have to fear is fear itself.
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
  if(n % 4) cout << "NO\n";
  else{
   cout << "YES\n";
   int t = n / 2;
   int sum = 0, s = (2*t + 2)*t/2;
   for(int i=1;i<=t;i++) cout << 2*i << " ";
   for(int i=1;i<t;i++){
    cout << 2*i -1 << ' ';
    sum += 2*i-1;
   }
   cout << s - sum << "\n";
  }  
 }
 
 return 0;
}