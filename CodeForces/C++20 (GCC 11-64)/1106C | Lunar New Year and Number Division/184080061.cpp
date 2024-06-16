#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
  
 int n; cin >> n;
 int a[n]; for(int &i: a) cin >> i;
 sort(a, a + n);
 
 int l = 0, r = n - 1;
 long long ans = 0;
 while(l < r)
 {
  ans += 1ll * (a[l] + a[r]) * (a[l] + a[r]);
  ++l; --r;
 }  
 cout << ans;
 return 0;
}