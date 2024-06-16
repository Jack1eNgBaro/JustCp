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
 int n, k, h; cin >> n >> k >> h;
 int a[n + 1]; for(int i=1;i<=n;i++) cin >> a[i];
 
 int ans = 0, sum = 0;
 for(int i=1;i<=n;i++){
  if(sum + a[i] <= k){
   sum += a[i];
  }else{
   ans++; sum = a[i];
  }
  ans += sum / h;
  sum %= h;
 }
 ans += sum / h;
 sum %= h;
 if(sum) ans++;
 cout << ans;
 return 0;
}