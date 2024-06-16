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
  int a[n]; for(int &i: a) cin >> i;
  int b[n]; for(int &i: b) cin >> i;
  int ami = *min_element(a, a + n);
  int bmi = *min_element(b, b + n);
  
  int ans = 0;
  for(int i=0;i<n;i++){
   int ta = a[i] - ami;
   int tb = b[i] - bmi;
   
   int t = min(ta, tb);
   ans += t;
   a[i] -= t;
   b[i] -= t;
   
   if(a[i] > ami) ans += (a[i] - ami);
   if(b[i] > bmi) ans += (b[i] - bmi);
  }
  cout << ans << "\n";  
 }
 return 0;
}