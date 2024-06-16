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
 while(tc--){
  int n, k; cin >> n >> k;
  if(k % (n - 1)){
   cout << (k / (n - 1)) * n + (k % (n - 1)) << "\n";
  }else{
   cout << (k / (n - 1)) * n - 1 << "\n";
  }
 }
 return 0;
}