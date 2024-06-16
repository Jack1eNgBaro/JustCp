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
 int n, k; cin >> n >> k;
 int a[n + 1]; for(int i=1;i<=n;i++) cin >> a[i];
 
 int ans = 1e9;
 int s = 0, id = 1;
 for(int i=1;i<=k;i++) s += a[i];
 ans = s;
 
 for(int i=2;i+k-1<=n;i++){
  s -= a[i - 1];
  s += a[i + k - 1];
  if(s < ans){
   s = ans; id = i;
  }
 }
 cout << id;
 return 0;
}