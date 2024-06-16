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
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, k, q; cin >> n >> k >> q;
  int a[n + 1], ans = 0;
  for(int i=1;i<=n;i++) cin >> a[i];
 
  multiset<int> ms;
  for(int l=1,i=1;i<=n;i++){
   ms.insert(a[i]);
   while(l<=i && *ms.rbegin() > q){
    ms.erase(a[l]);
    ++l;
   }
   if(i-l+1>=k){
    ans += (i-l+1)-k+1;
   }
  }
  cout << ans << "\n";
 }
 return 0;
}