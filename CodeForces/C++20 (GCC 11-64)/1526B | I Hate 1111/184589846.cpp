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
  if(n % 11 == 0){
   cout << "YES\n";
  }
  else{
   int ok = 0;
   for(int i=0;i<=n/11;i++)
   {
    int x = n - 11 * i;
    if(x % 111 == 0){
     ok = 1;
     break;
    }
   }
   if(ok) cout << "YES\n";
   else cout << "NO\n";
  }
 }
   
 return 0;
}