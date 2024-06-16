#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int mod = 1e8;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n1, n2, k1, k2;
int dp[105][105][15][15];
int call(int h, int f, int i1, int i2)
{
 if(dp[h][f][i1][i2] != -1) return dp[h][f][i1][i2];
 if(h == 0 && f == 0) return 1;
 
 int opt1 = 0, opt2 = 0;
 if(i1 < k1 && h > 0){
  opt1 += (call(h - 1, f, i1 + 1, 0) % mod);
 }
 if(i2 < k2 && f > 0){
  opt2 += (call(h, f - 1, 0, i2 + 1) % mod);
 }
 
 return dp[h][f][i1][i2] = (opt1 + opt2) % mod;
}
main()
{
 file();
 cin >> n1 >> n2 >> k1 >> k2;
 memset(dp, -1, sizeof(dp));
 cout << call(n1, n2, 0, 0) % mod;
 return 0;
}