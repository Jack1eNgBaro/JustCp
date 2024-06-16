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
  vector<int> a(n), b(n);
  
  int ca = 0, cb = 0;
  for(int &i: a) cin >> i, ca += (i == 1);
  for(int &i: b) cin >> i, cb += (i == 1);
  
  int ans = 0, res = 1 + abs(ca - cb);
  for(int i=0;i<n;i++)
   if(a[i] != b[i]) ++ans;
  cout << min(ans, res) << "\n";
 }  
   
 return 0;
}