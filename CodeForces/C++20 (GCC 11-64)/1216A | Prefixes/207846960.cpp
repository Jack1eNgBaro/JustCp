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
 
int f[maxn + 1];
int main()
{
 file();
 int n; cin >> n;
 string s; cin >> s;
 s = "~" + s;
 int ans = 0;
 for(int i=1;i<=n;i++){
  f[i] = f[i - 1] + (s[i] == 'a');
  if(i%2==0){
   int a = f[i];
   if(a > i/2){
    ans += a - i/2;
    if(s[i] == 'a') s[i] = 'b';
    else s[i - 1] = 'b';
   }else if(a < i/2){
    ans += i/2 - a;
    if(s[i] == 'b') s[i] = 'a';
    else s[i - 1] = 'a';
   }
   f[i] = i / 2;
  }
 } 
 s.erase(0,1);
 cout << ans << "\n" << s;
 return 0;
}