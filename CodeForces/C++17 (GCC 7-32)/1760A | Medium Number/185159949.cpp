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
  int a[3]; for(int &i: a) cin >> i;
  sort(a, a + 3);
  cout << a[1] << "\n";
 }
   
 return 0;
}