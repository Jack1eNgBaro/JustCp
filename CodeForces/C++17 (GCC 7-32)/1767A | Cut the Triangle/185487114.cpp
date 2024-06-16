#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
 
pii makevecto(pii a, pii b){
 pii ans;
  ans = {b.first - a.first, b.second - a.second};
 return ans;
}
 
pii ox = {1, 0};
pii oy = {0, 1};
 
bool kt(pii x, pii y){
 int t = x.first * y.first + x.second * y.second;
 return t == 0;
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 int tc; cin >> tc;
 while(tc--)
 {
  int n = 3;
  vector<pii> a;
  for(int i=0;i<n;i++)
  {
   int x, y; cin >> x >> y;
   a.push_back({x, y});
  }
  
  auto d1 = makevecto(a[0], a[1]);
  auto d2 = makevecto(a[1], a[2]);
  auto d3 = makevecto(a[0], a[2]);
 
  int ok = 1;
  int c1 = 0, c2 = 0;
  
  if(kt(d1, ox) || kt(d2, ox) || kt(d3, ox)) c1 = 1;
  if(kt(d1, oy) || kt(d2, oy) || kt(d3, oy)) c2 = 1;
  
  if(c1 && c2) ok = 0;
  
  if(ok) cout << "YES\n";
  else cout << "NO\n";
 }
 
 return 0;
}