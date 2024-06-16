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
 int d2, d3, d5, d6; cin >> d2 >> d3 >> d5 >> d6;
 int t = min({d2, d5, d6});
 d2 -= t; d5 -= t; d5 -= t;
 
 int ans = 0; 
 ans += 256 * t;
 
 t = max(0ll, min(d2, d3));
 ans += 32 * t;
 
 cout << ans;
 return 0;
}