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
const int maxn = 1005;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
struct node{
 int val, id;
};
bool cmp(node a, node b){
 return a.val < b.val;
}
 
vector<pii> v;
void solve(node a[], int n){
 v.clear();
 if(n == 1) return cout << "0\n", void();
 sort(a + 1, a + n + 1, cmp);
 if(a[1].val == a[n].val) return cout << "0\n", void();
 if(a[1].val == 1) return cout << "-1\n", void();
 
 while(1 + 1 == 2){
  sort(a + 1, a + n + 1, cmp);
  if(a[1].val == a[n].val) break;
  a[n].val = (a[1].val + a[n].val - 1) / a[1].val;
  v.push_back({a[n].id, a[1].id});
 }
 cout << v.size() << "\n";
 for(auto it: v){
  cout << it.first << ' ' << it.second << "\n";
 }
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  node a[n + 1]; 
  for(int i=1;i<=n;i++){
   cin >> a[i].val; a[i].id = i;
  }
  solve(a, n);  
 }
 return 0;
}