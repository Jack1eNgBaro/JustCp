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
 
const int maxn = 2e5;
const int mod = 1e9 + 7;
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
 int n, k; cin >> n >> k;
 set<int> se;
 vector<int> v;
 for(int i=1;i<=n;i++){
  int x; cin >> x;
  if(!se.count(x)){
   se.insert(x);
   v.push_back(i);
  }
 }
 if(se.size() < k) return cout << "NO\n", 0;
 cout << "YES\n";
 for(int i=0;i<k;i++) cout << v[i] << " ";
 return 0;
}