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
 
int kt(int n){
 for(int i=2;i<=sqrt(n);i++){
  if(n % i == 0){
   int cnt = 0;
   while(n % i == 0){
    n /= i; ++cnt;
   }
   if(cnt >= 2) return 0;
  }
 }
 return 1;
}
 
main()
{
 file();
 int n; cin >> n;
 int ans = 0;
 for(int i=1;i<=sqrt(n);i++){
  if(n % i == 0){
   if(kt(i)) ans = max(ans, i);
   if(kt(n / i)) ans = max(ans, n / i);
  }
 }
 cout << ans;
 return 0;
}