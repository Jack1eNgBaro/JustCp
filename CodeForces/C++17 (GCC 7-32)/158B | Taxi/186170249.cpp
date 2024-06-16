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
 
int d[5];
int main()
{
 file();
 int n; cin >> n;
 for(int i=0;i<n;i++)
 {
  int x; cin >> x;
  d[x]++;
 } 
 int ans = d[4];
 int t = min(d[1], d[3]);
 ans += t;
 d[3] -= t; d[1] -= t;
 ans += d[3];
 
 ans += d[2] / 2;
 if(d[2] % 2 == 0) d[2] = 0;
 else d[2] = 1;
 
 if(d[2] == 1){
  ans++;
  d[1] -= min({d[1], 2});
 }
 ans += d[1] / 4;
 if(d[1] % 4) ans++;
 
 cout << ans << "\n";
 
 return 0;
}