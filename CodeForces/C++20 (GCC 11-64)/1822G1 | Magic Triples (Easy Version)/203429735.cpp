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
 
int c3n(int n){
 return n*(n-1)*(n-2);
} 
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  map<int,int> mp;
  set<int> se;
  for(int i=1;i<=n;i++){
   int x; cin >> x;
   mp[x]++;
   se.insert(x);
  }
  int ans = 0;
  for(auto x: se){
   vector<int> v;
   for(int i=1;i<=sqrt(x);i++){
    if(x % i == 0){
     v.push_back(i);
     if(i * i != x) v.push_back(x / i);
    }
   }
//   sort(v.begin(), v.end());
   for(auto t: v){
    if(!mp.count(t)) continue;
    int d = x / t;
    if(d == 1){
     ans += c3n(mp[x]);
    }else{
     ans += mp[t] * mp[x] * mp[x*d];
    }
   }
  }
  cout << ans << "\n";
 }
 return 0;
}
 