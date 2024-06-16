#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
 
bool cmp(pii a, pii b){
 if(a.first != b.first)
  return a.first < b.first;
 return a.second < b.second;
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int n; cin >> n;
 vector<pii> a;
 for(int i=0;i<n;i++){
  int x, y; cin >> x >> y;
  a.push_back({x, y});
 }
 sort(a.begin(), a.end(), cmp);
 
 int ans = a[0].second, prev = a[0].second;
 for(int i=1;i<n;i++){
  if(a[i].second < prev){
   ans = a[i].first;
  }else{
   ans = a[i].second;
  }
  prev = ans;
 }
 cout << ans;
    return 0;
}