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
 if(s.size() == 1) cout << 0;
 else{
  int ans = 0;
  while(1){
   int sum = 0;
   if(s.size() == 1) break;
   for(char c: s){
    sum += (c - '0');
   }
   s = to_string(sum);
   ++ans;
  }
  cout << ans;
 }
 return 0;
}