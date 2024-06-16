#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int n; cin >> n;
 int a[n]; for(int &i: a) cin >> i;
 
 vector<int> v;
 
 int dem = 0, cur = 0;
 for(int i=0;i<n;i++){
  if(i == 0){
   cur = a[i];
   ++dem;
  }else{
   if(a[i] == cur)++dem;
   else{
    cur = a[i];
    v.push_back(dem);
    dem = 1;
   }
  }
 }
 v.push_back(dem);
 
 int ans = 0;
 for(int i=1;i<v.size();i++){
  ans = max(ans, min(v[i], v[i - 1]) * 2);
 }cout << ans;
 return 0;
}