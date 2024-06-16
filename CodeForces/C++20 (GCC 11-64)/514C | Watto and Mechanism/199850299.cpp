/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 257;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m, p[maxn + 1];
 
set<int> se;
 
int gohash(string s){
 int ans = 1;
 for(char ch: s){
  int c = ch - 'a' + 1;
  ans = (ans * base + c) % mod;  
 }
 return ans ;
}
 
void solve(string s){
 int h = gohash(s);
 for(int i=0;i<s.size();i++){
  for(int c=1;c<=3;c++){
   int x = s[i] - 'a' + 1;
   if(x == c) continue;
   int nh = ((h + (c - x) * p[s.size() - i - 1]) % mod + mod) % mod;
//   cout << nh << ' ';
   if(se.count(nh)){
    return cout << "YES\n", void();
   }
  }
//  cout << "\n";
 }
// cout << "\n";
 cout << "NO\n", void();
}
 
main()
{
 file();
 p[0] = 1;
 for(int i=1;i<=maxn;i++) p[i] = (p[i - 1] * base) % mod;
 
 cin >> n >> m;
 for(int i=1;i<=n;i++){
  string s; cin >> s;
  int t = gohash(s);
  se.insert(t);
//  cout << t << ' ';
 }
// cout << "\n";
 
 while(m--){
  string t; cin >> t;
  solve(t);
 }
 
 return 0;
}