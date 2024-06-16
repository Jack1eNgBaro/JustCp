#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
 
int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, k;
vector<int> f, g;
 
int main()
{
 file();
 cin >> n >> mod;
 vector<int> a, b;
 for(int i=0;i<n;i++){
  int x; cin >> x;
  if(i < n / 2) a.push_back(x);
  else b.push_back(x);
 }
 
 int n = a.size(), m = b.size();
 for(int i=0;i<(1<<n);i++){
  int sum = 0;
  for(int j=n-1;j>=0;j--){
   if((i >> j) & 1){
    sum += a[j];
    sum %= mod;
   }
  }
  f.push_back(sum);
 }
 
 for(int i=0;i<(1<<m);i++){
  int sum = 0;
  for(int j=m-1;j>=0;j--){
   if((i >> j) & 1){
    sum += b[j];
    sum %= mod;
   }
  }
  g.push_back(sum);
 }
 
 sort(f.begin(), f.end());
 sort(g.begin(), g.end());
 
 int ans = 0;
 for(auto x: g){
  auto it = lower_bound(f.begin(), f.end(), mod - x);
  --it;
  ans = max(ans, x + *it);
 }
 cout << ans << "\n";
 return 0;
}