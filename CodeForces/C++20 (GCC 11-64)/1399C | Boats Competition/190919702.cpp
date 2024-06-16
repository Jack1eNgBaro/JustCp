#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
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
 
int count(map<int,int> mp, int x){
 int ans = 0;
 for(int i=1;i<=(x - 1)/2;i++){
  ans += min(mp[i], mp[x - i]);
 }
 if(x % 2 == 0) ans += (mp[x / 2] / 2);
 return ans;
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  map<int,int> mp;
  for(int i=1;i<=n;i++){
   int x; cin >> x;
   mp[x]++;
  }
  
//  cout << count(mp, 12) << "\n";
  
  int ans = 0;
  for(int msk=2;msk<=2*n;msk++)
   ans = max(ans, count(mp, msk));
  cout << ans << "\n";  
 }
 return 0;
}