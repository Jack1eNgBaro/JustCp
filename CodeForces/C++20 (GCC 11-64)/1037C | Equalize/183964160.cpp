#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int n; cin >> n;
 vector<int> a(n), b(n);
 
 int c1 = 0, c2 = 0;
 
 for(int &x: a){
  char c; cin >> c;
  x = c - '0';
  c1 += x;
 }
 for(int &x: b){
  char c; cin >> c;
  x = c - '0';
  c2 += x;
 } 
 
// for(auto x: a) cout << x << ' '; cout << "\n";
// for(auto x: b) cout << x << ' '; cout << "\n";   
   
 int ans = 0;  
 deque<int> d0, d1;
 for(int i=0;i<n;i++)
 {
  if(a[i] == b[i]) continue;
  if(a[i] == 0)
   d0.push_back(i);
  else
   d1.push_back(i);
  if(d0.size() && d1.size() && abs(d1.back() - d0.back()) < 2)
  {
//   cout << d0.back() << ' ' << d1.back() << "\n";
   ans++;
   d0.pop_back(); d1.pop_back();
  }
 } 
  
 while(d0.size()){
  ans++; d0.pop_back();
 }
 
 while(d1.size()){
  ans++; d1.pop_back();
 }
 
 cout << ans;
   
 return 0;
}