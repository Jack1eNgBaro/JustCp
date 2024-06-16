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
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  string s; cin >> s;
  s = "~" + s;
  
  int pos = 0;
  for(int i=1;i<=n-1;i++)
  {
   if(s[i] == 'L' && s[i + 1] == 'R'){
    swap(s[i], s[i + 1]);
    pos = i;
    break;
   }
  }
  
  int ok = 0;
  for(int i=1;i<=n-1;i++){
   if(s[i] == 'R' && s[i + 1] == 'L') ok = 1;
  }
  
  if(ok){
   cout << pos << "\n";
  }
  else cout << "-1\n";
  
 }
 return 0;
}