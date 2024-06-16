#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int v1, v2; cin >> v1 >> v2;
 int n, d; cin >> n >> d;
 
 int ans = v1;
 for(int i=1;i<=n-2;i++){
  ans += min(v1 + i*d, v2 + (n - 1)*d - i * d);
 }
 cout << ans + v2;
 return 0;
}