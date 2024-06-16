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
 
int a[maxn + 1], b[maxn + 1];
main()
{
 file();
 int n, d; cin >> n >> d;
 vector<pii> v;
 for(int i=1;i<=n;i++){
  int x, y; cin >> x >> y;
  v.push_back({x, y});
 }
 sort(v.begin(), v.end());
 
 for(int i=1;i<=n;i++){
  a[i] = v[i - 1].first;
  b[i] = b[i - 1] + v[i - 1].second;
 }
 
 int ans = 0;
// for(int i=1;i<=n;i++) cout << a[i] << ' '; cout << '\n'; 
 for(int i=1;i<=n;i++)
 {
  int j = upper_bound(a + i + 1, a + n + 1, a[i] + d - 1) - a;
//  cout << i << ' ' << j << "\n";
  ans = max(ans, 1ll * b[j - 1] - b[i - 1]);
 }
 cout << ans;
 return 0;
}