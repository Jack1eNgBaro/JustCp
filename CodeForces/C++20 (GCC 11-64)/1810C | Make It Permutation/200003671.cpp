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
  int n, db, rr; cin >> n >> db >> rr;
  vector<int> a, f(n + 1, 0);
  
  a.push_back(0);
  for(int i=0;i<n;i++){
   int x; cin >> x;
   a.push_back(x);
  }
  sort(a.begin(), a.end());
 
  map<int,int> mp;
  for(int i=1;i<=n;i++){
   if(!mp.count(a[i])) mp[a[i]] = i;
  }  
  
  f[0] = 0;
  for(int i=1;i<=n;i++){
   int kc = a[i] - a[i - 1];
   if(kc == 1) f[i] = f[i - 1];
   else{
    if(a[i] != a[i - 1]) f[i] = f[i - 1] + rr*(kc-1); 
    else{
     f[i] = f[i - 1] + db;
    }
   }
  }
  
  int ans = f[0] + rr + n*db;
  for(int i=1;i<=n;i++){
//   cout << f[i] << ' ';
   int j = mp[a[i]];
   ans = min(ans, f[i] + (n-j)*db);
  }
  cout << ans << "\n";
//  for(int i=1;i<=n;i++) cout << a[i] << ' '; cout << '\n';
//  for(int i=1;i<=n;i++){
//   cout << f[i] << ' ';
//  }
 
 }
 
 return 0;
}