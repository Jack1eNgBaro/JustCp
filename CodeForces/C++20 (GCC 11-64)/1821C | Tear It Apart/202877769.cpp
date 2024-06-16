/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
//int poww(int a, int b){
// int ans = 1;
// while(b){
//  if(b&a) ans *= a;
//  a *= a;
//  b >>= 1;
// }
// return ans;
//}
//
//vector<int> cal;
//void init(){
// for(int i=1;i<20;i++){
//  cal.push_back(poww(2, i) - 1);
// }
//}
//
//int sol(int x){
// auto it = upper_bound(cal.begin(), cal.end(), x);
// --it;
// return it - cal.begin();
//}
 
int main()
{
 file();
// init();
 
 int tc; cin >> tc;
 while(tc--){
  string s; cin >> s;
  map<char,vector<int>> mp;
  for(int i=0;i<s.size();i++){
   mp[s[i]].push_back(i + 1);
  }
  int ans = 1e9;
  for(auto it: mp){
   vector<int> a, v = it.second;
   a.push_back(v[0]-1);
   for(int i=1;i<v.size();i++){
    a.push_back(v[i]-v[i-1]-1);
   }
   a.push_back(s.size()-v[v.size()-1]);
   
//   cout << it.first << ": ";
//   for(auto x: a) cout << x << ' '; cout << "\n";
   
   int s = 0;
   while(1 + 1 == 2){
    int mx = *max_element(a.begin(), a.end());
    if(mx == 0) break;
    ++s;
    int ok = 0;
    for(auto &x: a){
     x -= (x + 1) / 2;
     if(x > 0) ok = 1;
    }
    if(!ok) break;
    
   }
   ans = min(ans, s);
//   int s = 0;
//   for(auto x: a){
//    s += sol(x);
//   }
//   ans = min(ans, s);
  }
  cout << ans << "\n";
 }
 return 0;
}