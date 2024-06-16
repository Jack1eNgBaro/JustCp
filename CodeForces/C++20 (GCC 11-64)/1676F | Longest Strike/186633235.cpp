#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
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
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  int n, k; cin >> n >> k;
  int a[n]; for(int &i: a) cin >> i;
  sort(a, a + n);
  
  vector<pii> v;
  int val = a[0], cnt = 1;
  for(int i=1;i<n;i++){
   if(a[i] == a[i - 1])++cnt;
   else{
    v.push_back({val, cnt});
    val = a[i];
    cnt = 1;
   }
  }
  v.push_back({val, cnt});
  sort(v.begin(), v.end());
//  for(auto it: v){
//   cout << it.first << ' ' << it.second << "\n";
//  }
//  cout << "\n";
  n = v.size(); cnt = 0;
  int ans = -1, fs = 0;
  pii res;
  for(int i=0;i<n;i++){
   if(fs == 0){
    if(v[i].second >= k){
     fs = 1; cnt = 1;
    }
   }else{
    if(v[i].first == v[i-1].first + 1 && v[i].second >= k){
     ++cnt;
    }else if(v[i].first != v[i-1].first + 1 && v[i].second >= k){
     cnt = 1;
    }else{
     fs = 0; cnt = 0;
    }
   }
   if(cnt > ans){
    ans = cnt;
    res = {v[i].first - ans + 1, v[i].first};
   }
  }
//  cout << ans << "\n";
  if(ans){
   cout << res.first << " " << res.second << "\n";
  }else{
   cout << "-1\n";
  }
 }
 return 0;
}