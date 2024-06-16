#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
 int n; cin >> n;
 int s = 0, a[n + 2];
 for(int i=1;i<=n;i++){
  cin >> a[i];
  s += a[i];
 }
 if(s % 3 != 0) return cout << 0, 0;
 
 int val = s / 3;
 vector<int> cnt(n + 5, 0); //So Luong doan [j, n] = s
 s = 0;
 for(int i=n;i>=1;i--){
  s += a[i];
  if(s == val) cnt[i] = 1;
 }
 for(int i=n;i>=1;i--) cnt[i] += cnt[i + 1];  
 
 long long ans = 0, ss = 0;
 for(int i=1;i<=n;i++){
  ss += a[i];
  if(ss == val){
   ans += cnt[i + 2];
  }
 }
 cout << ans;
 return 0;
}