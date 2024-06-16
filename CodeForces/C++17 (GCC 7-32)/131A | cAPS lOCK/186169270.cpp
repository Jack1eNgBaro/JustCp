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
 string s; cin >> s;
 
 int cnt = 0;
 for(char c: s){
  if(c >= 'A' && c <= 'Z') ++cnt;
 }
 
 if(cnt == s.size()){
  for(char c: s) cout << char(tolower(c));
 }else if((cnt == s.size() - 1 && s[0] >= 'a' && s[0] <= 'z')){
  s[0] = toupper(s[0]);
  for(int i=1;i<s.size();i++) s[i] = tolower(s[i]);
  cout << s;
 }
 else cout << s;
 
 return 0;
}