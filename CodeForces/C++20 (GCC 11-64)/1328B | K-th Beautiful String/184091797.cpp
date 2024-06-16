#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn  = 1e5;
vector<ll> f(maxn + 1, 0);
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 f[0]= 0;
 f[1] = 1;
 for(ll i=0;i<=maxn;i++) f[i] = i * (i + 1) / 2;
 
// for(ll i=1;i<=maxn;i++) cout << f[i] << ' ';
 
 ll tc; cin >> tc;
 while(tc--)
 {
  ll n, k; cin >> n >> k;
  vector<char> s(n + 5, 'a');
  if(k == 1){
   s[n] = s[n - 1] = 'b';
  }
  else{
   auto it = lower_bound(f.begin(), f.end(), k);
   int i = it - f.begin();
   i = n - i;
   s[i] = 'b';
//   cout << *it - k << "\n";
   int j = max(0ll, i + *it - k + 1);
   s[j] = 'b';
//   cout << i << ' ' << j << "\n";
  }
  
  for(ll i=1;i<=n;i++) cout << s[i]; cout << "\n";
 }
   
 return 0;
}