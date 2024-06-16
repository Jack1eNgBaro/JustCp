/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
multiset<int> go(int n){
 multiset<int> ms;
 for(int i=2;i<=sqrt(n);i++){
  while(n % i == 0){
   ms.insert(i);
   n /= i;
  }
 }
 if(n != 1) ms.insert(n);
 return ms;
}
 
int gcd(int a, int b){
 if(b == 0) return a;
 return gcd(b, a % b);
}
 
main()
{
 file();
 int a, b; cin >> a >> b;
 if(a < b) swap(a, b);
 if(a == b) return cout << "0", 0;
 
 auto x = go(a);
 auto y = go(b);
 
 int ok = 1;
 int n = gcd(a, b);
 auto m1 = go(a/n);
 auto m2 = go(b/n);
 
 for(auto a: m1) if(a != 2 && a != 3 && a != 5) return cout << "-1\n", 0;
 for(auto a: m2) if(a != 2 && a != 3 && a != 5) return cout << "-1\n", 0;
 
 cout << (int)(m1.size()) + (int)(m2.size());
 
 return 0;
}