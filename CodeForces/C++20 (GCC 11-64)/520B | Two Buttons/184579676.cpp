//#include<bits/stdc++.h>
//using namespace std;
//#define pii pair<int,int>
//
//int n, m;
//queue<pii> q;
//set<int> se;
//
//int sol()
//{ 
// q.push({n, 0}); se.insert(n);
// while(!q.empty())
// {
//  pii f = q.front(); q.pop();
//  int x = f.first;
//  int y = f.second;
//  if(x == m) return y;
//  
//  if(!se.count(x * 2)){
//   se.insert(x * 2);
//   q.push({x * 2, y + 1});
//  }
//  
//  if(!se.count(x - 1)){
//   se.insert(x - 1);
//   q.push({x - 1, y + 1});
//  }
// }
//}
//
//int main(){
//// freopen("input.txt", "r", stdin);
//// freopen("output.txt", "w", stdout);
//
// std::ios::sync_with_stdio(0);
// cin.tie(0); cout.tie(0);
//   
// cin >> n >> m;
// cout << sol();
//   
// return 0;
//}
 
 
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
 
int n, m;
const int maxn = 1e5;
vector<int> adj[2 * maxn + 1];
int d[2 * maxn + 1];
 
int main()
{
 cin >> n >> m;
 for(int i=1;i<=maxn;i++)
 {
  int x = i;
  adj[x].push_back(x - 1);
  adj[x].push_back(x * 2);
  
  adj[x - 1].push_back(x);
  adj[x * 2].push_back(x);
 }
 
 queue<pii> q;
 q.push({n, 0});
 while(!q.empty())
 {
  pii f = q.front(); q.pop();
  int u = f.first, x = f.second;
//  cout << u << "\n";
  if(u == m){
   return cout << x << "\n", 0;
  }
  
  for(auto v: adj[u])
  {
   if(!d[v]){
    q.push({u - 1, x + 1});
    q.push({u * 2, x + 1});
    d[u - 1] = 1;
    d[u * 2] = 1;
   }
  }
 }
 
 return 0;
}