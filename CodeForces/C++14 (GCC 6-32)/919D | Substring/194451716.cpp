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
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m;
string s;
vector<int> adj[maxn + 1], radj[maxn + 1];
int dp[maxn + 1][26], in[maxn + 1];
 
main()
{
 file();
 cin >> n >> m;
 cin >> s; s = "~" + s;
 for(int i=1;i<=m;i++){
  int x, y; cin >> x >> y;
  adj[x].push_back(y);
  radj[y].push_back(x);
  in[y]++;
 }
 
 queue<int> q;
 for(int i=1;i<=n;i++){
  if(in[i] == 0) q.push(i);
//  dp[i][s[i] - 'a'] = 1;
 }
 
 vector<int> topo;
 int res = 0;
 while(q.size())
 {
  int u = q.front(); q.pop();
  topo.push_back(u);
  for(int v: adj[u]){
   in[v]--;
   if(in[v] == 0) q.push(v);
  }
  
  int mx[26]; memset(mx, 0, sizeof(mx));
  int idx = s[u] - 'a';
  for(int v: radj[u]){
   for(int i=0;i<26;i++){
    mx[i] = max(mx[i], dp[v][i]);
   }
  }
  for(int i=0;i<26;i++){
   dp[u][i] = mx[i] + (i == idx);
   res = max(res, dp[u][i]);
  }
 }
 if(topo.size() < n){
  cout << "-1\n"; return 0;
 }
 cout << res; 
 return 0;
}