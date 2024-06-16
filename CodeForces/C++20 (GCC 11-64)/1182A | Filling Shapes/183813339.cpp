#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll POW(ll a, ll b)
{
 ll ans = 1;
 while(b)
 {
  if(b & 1) ans = ans * a;
  a = a * a;
  b >>= 1;
 }
 return ans;
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int n; cin >> n;
 if(n % 2 == 1) return cout << 0, 0;
 else{
  cout << POW(2, n / 2);
 }
   
 return 0;
}