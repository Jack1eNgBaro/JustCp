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
  vector<int> f(n + 1, 0);
  for(int i=1;i<=n;i++){
   f[i] = i;
   int x; cin >> x;
   f[i] += x;
  }
  sort(f.begin() + 1, f.end());
//  for(int i=1;i<=n;i++) cout << f[i] << ' ';
//  cout << '\n';
  for(int i=1;i<=n;i++) f[i] += f[i - 1];
  
  auto it = upper_bound(f.begin() + 1, f.end(), k) - f.begin();
  if(it == 1) cout << "0\n";
  else cout << it - 1 << "\n";
  
 }
 return 0;
}