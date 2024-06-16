#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int n, q; cin >> n >> q;
 vector<int> a(n, 0), b(26, 0);
 
 string s; cin >> s; 
 while(q--){
  char c; cin >> c;
  b[c - 'a'] = 1;
 } 
 
 for(int i=0;i<n;i++)
 { 
  if(b[s[i] - 'a']) a[i] = 1;
  else a[i] = 0;
 }
   
 ll f[n];
 f[0] = (a[0] == 1);
 for(int i=1;i<n;i++){
  if(a[i] == 0) f[i] = 0;
  else f[i] = f[i - 1] + 1;
 } 
 
 ll ans = 0;
 for(auto x: f) ans += x; 
 cout << ans;
 return 0;
}