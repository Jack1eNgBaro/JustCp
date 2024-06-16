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
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  string s; cin >> s;
  set<pair<char,char>> se;
  for(int i=0;i+1<n;i+=1){
   se.insert({s[i], s[i + 1]});
  }
  cout << se.size() << "\n";
 }
 
 return 0;
}