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
 
bitset<64> bs;
main()
{
 file();
 int n; cin >> n;
 int s = n * (n + 1) / 2;
 
 set<int> ms;
 for(int i=1;i<=n;i++) ms.insert(i);
 
 int val = s / 2;
 cout << abs(2 * val - s) << "\n";
 
 s = val;
 vector<int> v;
 while(s){
  if(ms.count(s)){
   v.push_back(s);
   s = 0;
  }else{
   auto it = ms.upper_bound(s);
   --it;
   v.push_back(*it);
   ms.erase(it);
   s -= *it;
  }
 } 
 cout << v.size() << " "; for(auto x: v) cout << x << " ";
  
 return 0;
}