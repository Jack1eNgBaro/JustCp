#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll maxn = 1e6+1;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int main()
{
 file();
 ll tc; cin >> tc;
 while(tc--)
 {
  ll n; cin >> n;
  ll a[n + 1];
  for(ll i=1;i<=n;i++)
  {
   char c; cin >> c;
   a[i] = c - '0';
  }
  
  map<ll,ll> mp;
  mp[0] = 1;
  ll ans = 0, sum = 0;
  for(ll i=1;i<=n;i++)
  {
   sum += a[i];
   mp[sum - i]++;
  }
  for(auto t: mp){
   ll x = t.second;
   ans += x * (x - 1) / 2;
  }
  cout << ans << "\n";
 }
 return 0;
}