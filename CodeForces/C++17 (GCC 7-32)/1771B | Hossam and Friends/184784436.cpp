#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
 
main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--)
 {
  int n, m; cin >> n >> m;
  map<int,set<int>> mp;
  
  while(m--){
   int x, y; cin >> x >> y;
   if(x > y) swap(x, y);
   mp[y].insert(x);  
  }
  
  int ans = 0;
  for(int l=1,i=1;i<=n;i++){
   while(l <= i && mp[i].lower_bound(l) != mp[i].end()){
    ++l;
   }
   ans += i - l + 1; 
  }
  cout << ans << "\n";
 }
   
 return 0;
}