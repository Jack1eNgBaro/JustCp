#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 string s; cin >> s;
 int n = s.size();
 int p = -1, q = -1;
 for(int i=1;i<n;i++){
  if(s[i] == 'B' && s[i - 1] == 'A'){
   p = i; break;
  }
 }
 for(int i=n-2;i>=0;i--){
  if(s[i] == 'B' && s[i + 1] == 'A'){
   q = i; break;
  }
 }
 if(p != -1 && q != -1 && p < q) return cout << "YES", 0;
 p = -1, q = -1;
 for(int i=1;i<n;i++){
  if(s[i] == 'A' && s[i - 1] == 'B'){
   p = i; break;
  }
 }
 for(int i=n-2;i>=0;i--){
  if(s[i] == 'A' && s[i + 1] == 'B'){
   q = i; break;
  }
 }
 if(p != -1 && q != -1 && p < q) return cout << "YES", 0;
 cout << "NO\n";
 return 0;
}