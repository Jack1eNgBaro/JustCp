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
 
int n, k, a[maxn + 1];
 
int kt(int m){
 int s = 0;
 for(int i=(n+1)/2;i<=n;i++){
  if(a[i] < m){
   s += m - a[i];
  }
 }
 return s <= k;
}
 
main()
{
 file();
 cin >> n >> k;
 for(int i=1;i<=n;i++) cin >> a[i];
 sort(a + 1, a + n + 1);
 
 int l = a[(n + 1) / 2], r = 1e12;
 int ans = l;
 while(l <= r){
  int m = (l + r) / 2;
  if(kt(m)){
   ans = m;
   l = m + 1;
  }else r = m - 1;
 }
 cout << ans;
 return 0;
}