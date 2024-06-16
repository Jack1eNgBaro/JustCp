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
 
string ch[10] = {"", "", "2", "3", "223", "5", "35", "7", "7222", "7332"};
 
main()
{
 file();
 int n; cin >> n;
 string s, ans = ""; cin >> s;
 for(char c: s){
  ans += ch[c - '0'];
 }
 sort(ans.begin(), ans.end(), greater<char>());
 cout << ans;
 return 0;
}