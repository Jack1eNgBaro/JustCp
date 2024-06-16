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
 
string t = "314159265358979323846264338327";
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  string s; cin >> s;
  int ans = 0;
  for(int i=0;i<s.size();i++){
   if(s[i] != t[i]) break;
   ans = i + 1;
  }
  cout << ans << "\n";
 }
 return 0;
}