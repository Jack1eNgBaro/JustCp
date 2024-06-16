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
  int n, k; cin >> n >> k;
  multiset<int> ms;
  for(int i=0;i<n;i++)
  {
   int x; cin >> x;
   ms.insert(x);
  }
  int ok = 0;
  for(auto x: ms){
   if(ms.count(x + k)){
    ok = 1; break;
   }
  } 
  if(ok) cout << "YES\n";
  else cout << "NO\n";
 }  
   
 return 0;
}