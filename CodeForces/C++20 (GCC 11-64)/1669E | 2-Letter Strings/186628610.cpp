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
 int tc; cin >> tc;
 void init();
// for(char c='a';c<='k';c++) cout << c << ' ';
 while(tc--)
 {
  int d[12][12];
  memset(d, 0, sizeof(d));
  int n; cin >> n;
  int ans = 0;
  while(n--){
   string s; cin >> s;
   for(int i=0;i<2;i++)
   {
    for(char c='a';c<='k';++c)
    {
     if(s[i] == c) continue;
     string a = s; a[i] = c;
     ans += d[a[0]-'a'][a[1]-'a'];
    }
   }
   d[s[0]-'a'][s[1]-'a']++;
  } 
  cout << ans << "\n";  
 }
 return 0;
}