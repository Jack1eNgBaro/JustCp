#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 int n; cin >> n;
 map<int,string> mp;
 
 mp[0] = "I love";
 mp[1] = "I hate";
 string combine = "that";
 string last = "it";
 
 if(n == 1){
  cout << mp[n % 2] + " " + last; 
 }else{
  for(int i=1;i<=n;i++){
   cout << mp[i % 2] << " ";
   if(i != n) cout << combine << " ";
  }
  cout << last;
 }
   
 return 0;
}