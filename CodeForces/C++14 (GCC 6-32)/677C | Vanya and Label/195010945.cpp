/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
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
 
int main()
{
 file();
 map<char,int> mp;
 int idx = 0;
 for(char c='0';c<='9';c++) mp[c] = idx++;
 for(char c='A';c<='Z';c++) mp[c] = idx++;
 for(char c='a';c<='z';c++) mp[c] = idx++;
 mp['-'] = idx++; mp['_'] = idx++;
 
 string s; cin >> s;
 ll cnt = 1;
 for(char c: s){
  int x = mp[c];
  for(int i=5;i>=0;i--){
   if(!bit(x, i)){
    cnt *= 3; cnt %= mod; 
   }
  }
 }
 cout << cnt;
 return 0;
}