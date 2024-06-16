#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int gcd(int a, int b){
 return b == 0 ? a : gcd(b, a % b);
}
 
main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int n, p = 1; cin >> n;
 set<int> v;
 for(int i=1;i<=n;i++)
  if(gcd(i, n) == 1) 
   v.insert(i), p = (p * i) % n;
 if(p != 1) v.erase(p);
 cout << v.size() << "\n";
 for(auto x: v) cout << x << ' ';   
 return 0;
}