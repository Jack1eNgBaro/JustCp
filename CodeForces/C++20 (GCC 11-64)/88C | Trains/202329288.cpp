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
 
int gcd(int a, int b){
 if(b == 0) return a;
 return gcd(b, a % b);
}
 
int lcm(int a, int b){
 return a / gcd(a, b) * b; 
}
 
main()
{
 file();
 int a, b; cin >> a >> b;
 int m = lcm(a, b);
 
 int x = m / a; //Dasha
 int y = m / b; //Masha
 
 if(x < y) ++x;
 if(y < x) ++y;
 
 if(x == y) cout << "Equal";
 else if(x > y) cout << "Dasha";
 else cout << "Masha";
 
 return 0;
}