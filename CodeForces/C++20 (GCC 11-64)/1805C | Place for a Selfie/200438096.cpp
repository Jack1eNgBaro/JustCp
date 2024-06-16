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
  int n, m; cin >> n >> m;
  multiset<double> se;
  for(int i=1;i<=n;i++){
   int x; cin >> x;
   se.insert(x);
  }
  
  while(m--){
   int a, b, c; cin >> a >> b >> c;
   double x = 4*a*c;
   if(c > 0){
    double t1 = 1.0 * -sqrt(x)+b;
    double t2 = 1.0 * sqrt(x)+b;
    auto i1 = se.upper_bound(t1);
    if(i1 != se.end() && *i1 < t2){
     cout << "YES\n";
     cout << (int)*i1 << "\n";
    }
    else cout << "NO\n";
   }else cout << "NO\n";
  }
  cout << "\n";  
 }
 
 return 0;
}