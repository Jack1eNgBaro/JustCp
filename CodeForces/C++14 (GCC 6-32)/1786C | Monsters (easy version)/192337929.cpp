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
 while(tc--){
  int n; cin >> n;
  vector<int> a(n); for(int &i: a) cin >> i;
  if(n == 1){
   cout << a[0] - 1 << "\n";
  }else{
   sort(a.begin(), a.end()); 
   int cnt = 0, ans = 0;
   for(int i=0;i<n;i++){
    if(a[i] == cnt || a[i] == cnt + 1){
     cnt = a[i];
    }else{
     ans += (a[i] - cnt - 1);
     ++cnt;
    }
   }
   cout << ans << "\n";
  }
 }
 return 0;
}