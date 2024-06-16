#include<bits/stdc++.h>
using namespace std;
 
#define int unsigned long long
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
 int n, k; cin >> n >> k;
 int a[n]; for(int &i: a) cin >> i;
 sort(a, a + n);
 int l = a[n/2], r = 1e12, ans = 0;
 while(l <= r){
  int m = (l + r) / 2;
  int cnt = 0;
  for(int i=n/2;i<n;i++){
   if(a[i]<m) cnt += (m-a[i]);
  }
  if(cnt <= k){
   ans = m;
   l = m + 1;
  }else{
   r = m - 1;
  }
 }
 cout << ans;
 return 0;
}