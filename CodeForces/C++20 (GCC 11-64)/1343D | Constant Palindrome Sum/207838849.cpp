/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 31;
 
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
 while(tc--){
  int n, k; cin >> n >> k;
  int a[n + 1];
  for(int i=1;i<=n;i++) cin >> a[i];
  
  int mp[2 * k + 1];
  memset(mp, 0, sizeof(mp));
  
  for(int i=1;i<=n/2;i++){
   int x = a[i] + a[n - i + 1];
   mp[x]++;
  }
  
  vector<int> f(2*k + 5, 0);
  for(int i=1;i<=n/2;i++){
   int x = min(a[i], a[n - i + 1]) + 1;
   int y = max(a[i], a[n - i + 1]) + k;
   f[x]++;
   f[y+1]--;
  }
  for(int i=2;i<=2*k;i++) f[i] += f[i - 1];
  
  int ans = 1e9;
  for(int i=2;i<=2*k;i++){
   ans = min(ans, (f[i] - mp[i]) + (n/2 - f[i])*2);
  }
  //Them 1 - (so cap co tong = x roi (ko can them))
  //(n/2 - f[i])*2 may cap con lai ko the tao dc tong x thi can phai thay 2 gia tri
  cout << ans << '\n';
 }
 
 return 0;
}