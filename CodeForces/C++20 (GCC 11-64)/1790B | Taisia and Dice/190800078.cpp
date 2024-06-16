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
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, s, r; cin >> n >> s >> r;
  int mx = min(s - r, 6);
  vector<int> v;
  v.push_back(mx);
  
  for(int i=1;i<n;i++){
   int cur = 1;
   while(cur + n - i - 1 < r && cur < mx) ++cur;
   v.push_back(cur);
   r -= cur;
  }
  for(auto x: v) cout << x << " ";
  cout << "\n";
 }
 return 0;
}