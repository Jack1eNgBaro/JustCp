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
 
const int maxn = 1e6;
const int mod = 1e9 + 7;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, w, v[maxn + 1];
pii p[maxn + 1];
main()
{
 file();
 cin >> n >> w;
 for(int i=1;i<=n;i++) cin >> v[i];
 
 int a = 0, b = w;
 for(int i=1;i<=n;i++){
  a += v[i]; b += v[i];
  
  if(a < 0 && b < 0) return cout << 0, 0;
  a = max(0ll, a);
  b = max(0ll, b);
  
  if(a > w && b > w) return cout << 0, 0;
  a = min(a, w);
  b = min(b, w);
 } 
 cout << b - a + 1; 
 return 0;
}