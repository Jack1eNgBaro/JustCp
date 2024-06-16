#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
  
 int n, k; cin >> n >> k;
 int a[n + 1]; for(int i=1;i<=n;i++) cin >> a[i];
 int b[n + 1]; for(int i=1;i<=n;i++) cin >> b[i];
 
 int pre[n + 2] = {0};
 int suf[n + 2] = {0};
 for(int i=1;i<=n;i++) pre[i] = pre[i - 1] + a[i] * b[i];
 for(int i=n;i>=1;i--) suf[i] = suf[i + 1] + a[i] * b[i];
 
 ll sum = 0;
 for(int i=1;i<=k;i++)
  sum += a[i];
 ll ans = sum + suf[k + 1];
 for(int i=2;i<=n-k+1;i++)
 {
  sum -= a[i - 1];
  sum += a[i + k - 1];
  ans = max(ans, pre[i - 1] + sum + suf[i + k]); 
 }   
 cout << ans;
 return 0;
}