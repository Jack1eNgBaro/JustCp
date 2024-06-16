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
 
int mp[2506];
string s, t, tmp = "";
int ans = 0, dem = 0;
int main()
{
 file();
 cin >> s >> t;
 for(char c: t) mp[c]++;
 for(int i=0;i<s.size();i++){
  if(mp[s[i]] > 0){
   ans++;
   mp[s[i]]--;
  }else{
   tmp += s[i];
  }
 }
 for(char c: tmp){
  if(c >= 'a' && c <= 'z'){
   char x = toupper(c);
   if(mp[x] > 0){
    ++dem; mp[x]--;
   }
  }else{
   char x = tolower(c);
   if(mp[x] > 0){
    ++dem; --mp[x];
   }
  }
 }
 cout << ans << ' ' << dem;
 return 0;
}