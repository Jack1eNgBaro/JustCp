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
  int n, m; cin >> n >> m;
  multiset<int> ms;
  while(n--){
   int x; cin >> x;
   ms.insert(x);
  }
  while(m--){
   int x; cin >> x;
   auto it = ms.begin();
   ms.erase(it);
   ms.insert(x);
  }
  int s = 0;
  for(auto x: ms) s += x;
  cout << s << "\n";
 }
 return 0;
}