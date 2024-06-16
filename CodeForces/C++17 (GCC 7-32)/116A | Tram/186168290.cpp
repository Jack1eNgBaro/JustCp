#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
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
 
int main()
{
 file();
 int n; cin >> n;
 int res = 0, ans = 0;
 for(int i=1;i<=n;i++)
 {
  int x, y; cin >> x >> y;
  ans -= x;
  ans += y;
  res = max(res, ans);
 }
 cout << res;
 return 0;
}