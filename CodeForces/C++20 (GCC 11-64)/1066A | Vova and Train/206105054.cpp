/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
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
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, v, l, r; cin >> n >> v >> l >> r;
  int st = v, en = n/v*v;
  int x = (l-1)/v*v;
  int y = (r+v)/v*v;
  int ans = 0;
//  cout << st << ' ' << x << ' ' << y << ' ' << en << "\n";
  ans += (x - st + v) / v;
  ans += (en - y + v) / v;
  cout << ans << "\n";
 }
 
 return 0;
}