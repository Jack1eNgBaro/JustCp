/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
#define fi first
#define se second
#define vi vector<int> 
 
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
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, k; cin >> n >> k;
  unordered_map<int,vector<int>> mp;
  for(int i=0;i<n;i++){
   int x; cin >> x;
   mp[i%k].push_back(x);
  }
  ll ans = 0;
  for(int i=0;i<k;i++){
   #define v mp[i]
   sort(v.begin(), v.end(), greater<int>());
  }
  for(int i=0;i<k;i++){
   ans += mp[i%k][0];
  }
  cout << ans << "\n";
 }
 
 return 0;
}