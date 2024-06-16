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
const int maxn = 2e5;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
void sol(){
 int n; cin >> n;
 int a[n + 1]; for(int i=1;i<=n;i++) cin >> a[i];
 sort(a + 1, a + n + 1);
 
 if(a[1] != 1) return cout << "NO\n", void();
 int s = 1;
 for(int i=2;i<=n;i++){
  if(s < a[i]) return cout << "NO\n", void();
  else s += a[i];
 }
 cout << "YES\n";
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  sol();    
 }
 return 0;
}