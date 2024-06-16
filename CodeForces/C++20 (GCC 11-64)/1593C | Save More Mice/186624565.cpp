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
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  int n, k; cin >> n >> k;
  vector<pii> v;
  for(int i=0;i<k;i++){
   int x; cin >> x;
   v.push_back({n - x, x});
  }
  sort(v.begin(), v.end());
  int ans = 0, sum = 0;
  for(auto it: v){
//   cout << it.first << " " << it.second << "\n";
   if(it.second > sum){
    ans++;
    sum += it.first;
   }
  }
  cout << ans << "\n";
 }
 return 0;
}