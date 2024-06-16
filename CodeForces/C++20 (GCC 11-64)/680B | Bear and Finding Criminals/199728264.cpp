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
 int n, k; cin >> n >> k;
 int a[n + 1] = {0};
 for(int i=1;i<=n;i++) cin >> a[i];
 
 
 int ans = (a[k] == 1);
 
 int d = 1;
 while(d <= n){
  int x = k-d;
  int y = k+d;
  if(x >= 1 && y <= n){
   if(a[x]+a[y]==2) ans+=2;
  }else if(x >= 1){
   if(a[x]==1) ans++;
  }else if(y <= n){
   if(a[y]==1) ans++;
  }
  ++d; 
 }
 cout << ans;
 return 0;
}