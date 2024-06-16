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
 string t = "codeforces";
 while(tc--)
 {
  char c; cin >> c;
  if(t.find(c) != -1){
   cout << "Yes\n";
  }else{
   cout << "No\n";
  }
 }
 return 0;
}