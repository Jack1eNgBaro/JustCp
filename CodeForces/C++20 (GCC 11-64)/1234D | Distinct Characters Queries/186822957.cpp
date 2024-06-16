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
 
set<int> pos[26];
int main()
{
 file();
 string s; cin >> s;
 int n = s.size();
 s = "~" + s;
 for(int i=1;i<=n;i++) pos[s[i]-'a'].insert(i);
 
 int q; cin >> q;
 while(q--)
 {
  int type; cin >> type;
  if(type == 1)
  {
   int i; char c;
   cin >> i >> c;
   pos[s[i] - 'a'].erase(i);
   s[i] = c;
   pos[s[i] - 'a'].insert(i);
  }
  else
  {
   int l, r; cin >> l >> r;
   int ans = 0;
   for(int i=0;i<26;i++)
   {
    auto it = pos[i].lower_bound(l);
    if(it != pos[i].end() && *it <= r) ++ans;
   }
   cout << ans << "\n";
  }
 }
 
 return 0;
}