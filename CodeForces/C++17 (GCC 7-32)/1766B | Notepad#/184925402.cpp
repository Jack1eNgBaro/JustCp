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
  string s; cin >> s;
  
  if(n == 1){
   cout << "NO\n";
  }
  else{
   map<string,int> mp;
   
   string wd = "";
   wd = wd + s[0] + s[1];
   mp[wd]++;
   
   int cnt = 0;
   for(int i=1;i<=n-2;i++){
    string tmp = wd;
    wd = "";
    wd = wd + s[i] + s[i + 1];
    if(wd == tmp){
     ++cnt;
     if(cnt > 1) mp[wd]++;
    }
    else{
     mp[wd]++;
     cnt = 0;
    }
   }
   
   int ok = 0;
   for(auto x: mp){
    if(x.second >= 2) ok = 1;
   }
   if(ok) cout << "YES\n";
   else cout << "NO\n";
  }
 
 }
   
    return 0;
}