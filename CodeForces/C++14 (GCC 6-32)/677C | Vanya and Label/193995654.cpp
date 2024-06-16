#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
int powmod(int a, int b){
 int ans = 1;
 while(b){
  if(b & 1) ans = (ans * a) % mod;
  a = (a * a) % mod;
  b >>= 1;
 }
 return ans;
}
 
map<char,int> mp;
main()
{
 file(); int idx = 0;
 for(char c='0';c<='9';c++) mp[c] = idx++;
 for(char c='A';c<='Z';c++) mp[c] = idx++;
 for(char c='a';c<='z';c++) mp[c] = idx++;
 mp['-'] = 62; mp['_'] = 63;
 
 int cnt = 0; string str; cin >> str;
 int s = 0;
 for(char c: str){
  int x = mp[c];
  for(int i=5;i>=0;i--){
   if(bit(x, i) == 0) ++cnt;
  }
 }
 cout << powmod(3, cnt);
 return 0;
}