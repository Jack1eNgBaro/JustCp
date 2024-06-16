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
 int n, k; cin >> n >> k;
 int a[n + 1], pf[n + 1]; 
 memset(pf, 0, sizeof(pf));
 for(int i=1;i<=n;i++){
  cin >> a[i];
  pf[i] = pf[i - 1] + a[i];
 }
 
 int sum = 1e9, ans = 0;
 for(int i=1;i+k-1<=n;i++){
  if(pf[i + k - 1] - pf[i - 1] < sum){
   ans = i; sum = pf[i + k - 1] - pf[i - 1];
  }
 }
 cout << ans;
 return 0; 
}