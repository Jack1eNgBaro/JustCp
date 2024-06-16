#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int a, b, c; cin >> a >> b >> c;
 int ans = max
 ({
  a * b * c, 
  (a + b) * c, 
  a * (b + c),
  a + b + c,
 });
 cout << ans;
 return 0;
}