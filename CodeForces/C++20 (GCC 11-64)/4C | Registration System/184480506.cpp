#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int n; cin >> n;
 map<string,int> mp;
 
 while(n--)
 {
  string s; cin >> s;
  mp[s]++;
  if(mp[s] == 1) cout << "OK\n";
  else cout << s << mp[s] - 1<< "\n";
 }
   
 return 0;
}