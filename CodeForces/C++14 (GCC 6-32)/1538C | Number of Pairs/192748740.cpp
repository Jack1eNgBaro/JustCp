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
  int n, l, r; cin >> n >> l >> r;
  vector<int> a(n); for(int &i: a) cin >> i;
  sort(a.begin(), a.end());
  
  int ans = 0;
  for(int i=0;i<n;i++)
  {
   auto x = lower_bound(a.begin() + i + 1, a.end(), l - a[i]);
   auto y = upper_bound(a.begin() + i + 1, a.end(), r - a[i]);
   ans += (y - x);
  }  
  cout << ans << "\n";
 }
 return 0;
}