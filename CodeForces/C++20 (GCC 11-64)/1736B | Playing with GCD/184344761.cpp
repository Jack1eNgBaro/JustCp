#include<bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b){
 return (b == 0 ? a : gcd(b, a % b));
}
 
int lcm(int a, int b){
 return a / gcd(a, b) * b;
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  vector<int> a(n);
  for(int &i: a) cin >> i;
  
  if(n == 1){
   cout << "YES\n";
  }else{
   vector<int> b(n + 1);
   b[0] = a[0];
   b[n] = a[n - 1];
   for(int i=1;i<n;i++) b[i] = lcm(a[i - 1], a[i]);
   
   int ok = 1;
   for(int i=0;i<n;i++){
    if(a[i] != gcd(b[i], b[i + 1])) ok = 0;
   }
   cout << (ok ? "YES\n" : "NO\n");
  }
   
 }  
   
 return 0;
}