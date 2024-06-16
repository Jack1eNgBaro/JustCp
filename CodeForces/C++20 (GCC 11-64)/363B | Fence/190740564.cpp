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
 int n, k; cin >> n >> k;
 int sum = 0;
 int a[n]; for(int &i: a) cin >> i;
 for(int i=0;i<k;i++) sum += a[i];
 int ans = sum, idx = 0;
 for(int i=1;i<=n-k;i++){
  sum += a[i + k - 1];
  sum -= a[i - 1];
  if(sum < ans){
   ans = sum;
   idx = i;
  }
 }
 cout << idx + 1;
 return 0;
}