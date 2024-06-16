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
 vector<int> a(n); 
 for(int &i: a) cin >> i;
 sort(a.begin(), a.end());
 
 int ans = 0;
 for(int i=0;i<n-2;i++)
 {
  auto is = a.begin() + i + 2;
  auto it = upper_bound(is, a.end(), a[i] + k);
//  cout << i << ' ' << it - a.begin() << "\n";
  int x = (it - is) * (it - is + 1) / 2;
  ans += x;
 }
 cout << ans;
 return 0;
}