/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
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
 int n; cin >> n;
 map<int,int> mx, my;
 map<pii,int> mp;
 /*
  t = |x1-x2| + |y1-y2|
  => t^2 = (x1-x2)^2 + (y1-y2)^2
  
  s = sqrt((x1-x2)^2+(y1-y2)^2))
  => s^2 = (x1-x2)^2 + 2*|x1-x2|*|y1-y2| + (y1-y2)^2
  
  t == s 
  <=> x1 == x2 || y1 == y2
 */
 ll ans = 0;
 for(int i=0;i<n;i++){
  int x, y; cin >> x >> y;
  ans += mx[x]++; //x1 == x2
  ans += my[y]++; //y1 == y2
  ans -= mp[{x, y}]++; // {x1 == x2 && y1 == y2 bi tinh 2 lan nen phai tru ra=v}
 }
 cout << ans;
 return 0;
}