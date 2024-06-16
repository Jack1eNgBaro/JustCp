#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
int gcd(int a, int b){
 if(b == 0) return a;
 return gcd(b, a % b);
}
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
main()
{
 file();
 int n; cin >> n; 
 set<int> v;
  
 int p = 1;
 for(int i=1;i<=n;i++){
  if(gcd(i, n) == 1){
   v.insert(i);
   p = (p * i) % n;
  }
 }
 if(p != 1) v.erase(p);
  cout << v.size() << "\n";
 for(int x: v){
  cout << x << ' ';
 }
 return 0;
}