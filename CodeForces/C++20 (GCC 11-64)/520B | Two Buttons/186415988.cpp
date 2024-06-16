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
 
vector<int> adj[maxn + 1];
int used[maxn + 1], d[maxn + 1];
 
int main()
{
 file();
 int n, m; cin >> n >> m;
 for(int i=1;i<=1e4;i++)
 {
  adj[i].push_back(i * 2);
//  adj[i * 2].push_back(i);
  
  adj[i].push_back(i - 1);
//  adj[i - 1].push_back(i);
 }
 
 queue<int> q;
 q.push(n); 
 used[n] = 1;
 d[n] = 0;
 while(!q.empty())
 {
  int u = q.front(); q.pop();
  if(u == m){
   cout << d[m] << "\n";
   return 0; 
  }
  
  for(auto v: adj[u]){
   if(!used[v]){
    used[v] = 1;
    d[v] = d[u] + 1;
    q.push(v);
   }
  }
 }
 
 return 0;
}