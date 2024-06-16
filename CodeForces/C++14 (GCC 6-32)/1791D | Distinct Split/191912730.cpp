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
 while(tc--)
 {
  int n; cin >> n;
  string a; cin >> a;
  a = "~" + a;
  
  set<int> se;
  vector<int> f(n + 5, 0), g(n + 5, 0);
  for(int i=1;i<=n;i++){
   se.insert(a[i]);
   f[i] = se.size();
  }
  se.clear();
  for(int i=n;i>=1;i--){
   se.insert(a[i]);
   g[i] = se.size();
  }
  
  int ans = 0;
  for(int i=1;i<n;i++){
   ans = max(ans, f[i] + g[i + 1]);
  }
  cout << ans << "\n";
 }
 return 0;
}