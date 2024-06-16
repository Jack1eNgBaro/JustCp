#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  vector<pii> a;
  for(int i=0;i<n;i++){
   int x; cin >> x;
   a.push_back({x, i});
  }
  sort(a.begin(), a.end());
    
  int x = a[0].first, ans = 0;
  vector<pii> res;
  for(int i=1;i<n;i++){
   if(a[i].first == x) continue;
   if(a[i].first < x){
    ++ans;
    res.push_back({a[i].second, x - a[i].first});
    a[i].first = x;
   }else{
    int t = (a[i].first + x - 1) / x * x;
    int ok = (a[i].first != t);
    if(ok){
     ++ans;
     res.push_back({a[i].second, t - a[i].first});
    }
    a[i].first = t;
    x = t;
   }
  }
  cout << ans << "\n";
//  for(auto x: a) cout << x.first << " ";
//  cout << "\n";
  for(auto x: res){
   cout << x.first + 1 << ' ' << x.second << "\n";
  }
 }
   
 return 0;
}