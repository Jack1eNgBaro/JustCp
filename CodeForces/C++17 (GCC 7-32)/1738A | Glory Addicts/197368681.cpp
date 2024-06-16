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
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  int tp[n + 1], r[n + 1]; 
  for(int i=1;i<=n;i++) cin >> tp[i];
  for(int i=1;i<=n;i++) cin >> r[i];
  
  int s = 0;
  vector<int> a, b;
  for(int i=1;i<=n;i++){
   if(tp[i] == 0) 
    a.push_back(r[i]);
   else 
    b.push_back(r[i]);
   s += r[i];
  }
//  cout << a.size() << ' ' << b.size() << "\n";
  if(a.size() == 0 || b.size() == 0){
   cout << s << "\n"; continue;
  }  
  int d = min(a.size(), b.size()); d=2*d;
  int cnt, i, j;
  
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  
  int ans = 0;
  cnt = 0, i = 0, j = 0;
  while(i<a.size() && j<b.size() && cnt<d){
   ans += 2*(a[i]+b[j]); ++i; ++j; cnt+=2;
  }
  while(i<a.size()) ans += a[i++];
  while(j<b.size()) ans += b[j++];
  
  int res = 0;
  cnt = 0, i = 0, j = 0;
  while(i<a.size() && j<b.size() && cnt<d){
   res += 2*(a[i]+b[j]); ++i; ++j; cnt+=2;
  }
  while(i<a.size()) res += a[i++];
  while(j<b.size()) res += b[j++];
  
  if(d>=n) {ans -= a[a.size()-1]; res -= b[b.size()-1];}
  cout << max(ans, res) << "\n";
 }
 
 return 0;
}