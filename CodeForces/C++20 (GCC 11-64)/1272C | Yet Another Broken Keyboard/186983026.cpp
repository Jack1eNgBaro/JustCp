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
 
int ok[26], f[maxn + 1];
main()
{
 file();
 int n, k; cin >> n >> k;
 string s; cin >> s; 
 while(k--){
  char c; cin >> c;
  ok[c - 'a'] = 1;
 }
 memset(f, 0, sizeof(f));
 for(int i=0;i<n;i++)
 {
  if(ok[s[i] - 'a'] == 0) f[i] = 0;
  else f[i] = f[i - 1] + 1;
 }
 int ans = 0;
 for(int i=0;i<n;i++) ans += f[i];
 cout << ans;
 return 0;
}