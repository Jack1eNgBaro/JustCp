#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 int n, k; cin >> n >> k;
 int a[n]; for(int &i: a) cin >> i;
 
 int ans = 0, sum = 0;
 for(int l=0,i=0;i<n;i++)
 {
  sum += a[i];
  while(sum > k){
   sum -= a[l++];
  } 
  ans = max(ans, i - l + 1);
 }  
 cout << ans;
 return 0;
}