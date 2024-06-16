#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 ll tc; cin >> tc;
 while(tc--)
 {
  ll n; cin >> n;
  ll a[n + 1]; for(ll i=1;i<=n;i++) cin >> a[i];
  
  ll l = 1, r = n;
  ll s1 = 0, s2 = 0;
  ll ans = 0;
  
  while(l < r)
  {
   if(s1 + a[l] == s2 + a[r])
   {
    s1 += a[l]; s2 += a[r];
    ans = max(ans, l + n - r + 1);
    ++l; --r;
   }
   else if(s1 + a[l] > s2 + a[r]) s2 += a[r--];
   else s1 += a[l++];
//   cout << s1 << ' ' << s2 << "\n";
  }
  
  cout << ans << "\n";
 }
 
 
   
 return 0;
}