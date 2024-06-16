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
 int n, k; cin >> n >> k;
 int a[n + 1];
 a[0] = 0;
 for(int i=1;i<=n;i++){
  int x; cin >> x;
  a[i] = a[i - 1] + x;
 }
 
 int ans = 0;
 for(int i=1;i<=n;i++)
 {
  int j = upper_bound(a + i, a + n + 1, k + a[i - 1]) - a;
  if(i == j) continue;
//  cout << i << ' ' << j << "\n";
  ans = max(ans, j - i);
 }
 cout << ans;
 return 0;
}