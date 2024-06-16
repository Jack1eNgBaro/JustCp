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
 
int a[maxn + 1], f[maxn + 1];
main()
{
 file(); 
 int n, k; cin >> n >> k;
 
 f[0] = 0;
 for(int i=1;i<=n;i++){
  cin >> a[i];
  f[i] = f[i - 1] + a[i];
 }
 
 while(k--){
  int x; cin >> x;
  auto it = lower_bound(f + 1, f + n + 1, x);
  cout << it - f << " ";
  --it;
  cout << x - *it << "\n";
 }
 return 0;
}