#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int bit(int n, int i){
 return ((n >> i) & 1);
}
 
void solve(int x){
 if(x % 2 == 1){
  cout << "-1\n"; return;
 }
 int Sum = 2 * x;
 int And = Sum / 4;
 int Xor = x;
 int a = And, b = And;
 for(int i=31;i>=0;i--){
  if((bit(And, i) == bit(Xor, i)) && (bit(And, i) == 1)){
   cout << "-1\n"; return;
  }else if(bit(Xor, i) == 1)
   a += (1ll << i);
 }
 if(a + b == Sum){
  cout << a << " " <<  b << "\n";
 }else{
  cout << "-1\n";
 }
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int x; cin >> x;
  solve(x);
 }
 return 0;
}