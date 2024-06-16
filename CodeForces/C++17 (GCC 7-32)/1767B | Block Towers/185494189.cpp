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
  multiset<int> ms;
  int a[n]; for(int &i: a)
  {
   cin >> i;
   ms.insert(i);
  }
  int ans = a[0];
  ms.erase(ms.find(a[0]));
  
  for(auto x: ms){
   if(x > ans)
   {
    int t = x + ans;
    if(t % 2 == 0)
     ans = t / 2;
    else 
     ans = t / 2 + 1;
   }
  }
  cout << ans << "\n";  
 }
   
 return 0;
}