#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  char c; cin >> c;
  
  int ok = (c == '1');
  for(int i=1;i<n;i++){
   char x; cin >> x;
   if(x == '1'){
    if(ok == 0) 
     cout << '+', ok = 1;
    else 
     cout << '-', ok = 0; 
   }else cout << '+';
  }
  cout << "\n";
 }
   
 return 0;
}