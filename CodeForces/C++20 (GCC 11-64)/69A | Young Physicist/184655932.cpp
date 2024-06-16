#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 int n; cin >> n;
 int x = 0, y = 0, z = 0;
 while(n--)
 {
  int xx, yy, zz;
  cin >> xx >> yy >> zz;
  x += xx;
  y += yy;
  z += zz;
 }  
 if(x == 0 && y == 0 && z == 0){
  cout << "YES";
 }  else cout << "NO";
 return 0;
}