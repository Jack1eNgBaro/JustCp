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
  int n; cin >> n;
  int s = 0, cnt = 0;
  vector<int> a(n); for(int i=0;i<n;i++){
   cin >> a[i];
   if(a[i] < 0) ++cnt;
   s += abs(a[i]);
   a[i] = abs(a[i]);
  }
  
  int mi = *min_element(a.begin(), a.end());
  if(cnt % 2 == 0) cout << s << "\n";
  else cout << s - 2 * mi << "\n";
 }
 return 0;
}