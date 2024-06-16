/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 2005;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m, p;
int a[maxn + 1], b[maxn + 1];
int f[maxn + 1][maxn + 1];
 
main()
{
 file();
 cin >> n >> m >> p;
 for(int i=0;i<n;i++) cin >> a[i];
 sort(a, a + n);
 for(int i=0;i<m;i++) cin >> b[i];
 sort(b, b + m);
 
 for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) f[i][j] = 1e18;
 
 //f[i][j] ket qua cho i chia khoa dau va j nguoi dau sau khi sx
 f[0][0] = 0;
 for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
   f[i+1][j] = min(f[i+1][j], f[i][j]); //ko chon
   int x = abs(b[i] - a[j]) + abs(p - b[i]);
   f[i+1][j+1] = min(f[i+1][j+1], max(f[i][j], x));
  }
 }
 
 int ans = 1e18;
 for(int i=0;i<=m;i++) ans = min(ans, f[i][n]);
 cout << ans;
 return 0;
}