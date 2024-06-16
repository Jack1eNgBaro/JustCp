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
 
bool cmp(pii a, pii b){
 return (a.first - a.second) < (b.first - b.second);
}
 
main()
{
 file();
 int n, k; cin >> n >> k;
 vector<pii> v(n);
 for(int i=0;i<n;i++) cin >> v[i].first;
 for(int i=0;i<n;i++) cin >> v[i].second;
 
 sort(v.begin(), v.end(), cmp);
 int ans = 0;
 for(int i=0;i<n;i++){
  if(i < k) ans += v[i].first;
  else{
   ans += min(v[i].first, v[i].second);
  }
 }
 cout << ans;
 return 0;
}