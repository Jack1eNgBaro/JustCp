#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 3e5;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
string s;
int n, m, in[maxn + 1];
vector<int> adj[maxn + 1], radj[maxn + 1];
int dp[maxn + 1][26];
 
void inp()
{
 cin >> n >> m >> s;
 s = "~" + s;
 
 for(int i=1;i<=m;i++)
 {
  int x, y; cin >> x >> y;
  adj[x].push_back(y);
  radj[y].push_back(x);
  in[y]++;
 }
}
 
void process()
{
 queue<int> q;
 vector<int> topo;
 int ans = -1;
 for(int i=1;i<=n;i++){
  if(in[i] == 0){
   q.push(i);
   dp[i][s[i] - 'a'] = 1;
  }
   
 }
 
 while(q.size())
 {
  int u = q.front(); q.pop();
  topo.push_back(u);
  for(int v: adj[u]){
   in[v]--;
   if(in[v] == 0) q.push(v);
  }
  
  for(int v: radj[u]){
   for(int i=0;i<26;i++){
    dp[u][i] = max(dp[u][i], dp[v][i] + (s[u] - 'a' == i));
    ans = max(ans, dp[u][i]);
   }
  }
 }
 
 if(topo.size() < n){
  cout << "-1\n";
 }else{
  cout << ans << "\n";
//  for(auto x: topo) cout << x << " ";
//  for(int i=1;i<=n;i++){
//   cout << i <<":\n";
//   
//   int ok = 0;
//   for(int j=0;j<26;j++){
//    if(dp[i][j] != 0){
//     ok = 1;
//     cout << (char)('a' + j) << " " << dp[i][j] <<"\n";
//    }
//   }
//   if(ok)cout << "\n";
//  }
 }
}
 
int main()
{
 file();
 inp();
 process();
 return 0;
}