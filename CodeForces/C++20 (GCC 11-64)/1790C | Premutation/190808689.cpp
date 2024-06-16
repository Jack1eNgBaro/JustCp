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
 while(tc--){
  int n; cin >> n;
  priority_queue<int, vector<int>, greater<int>> q;
  
  vector<int> adj[n + 1];
  vector<int> in(n + 1, 0);
  
  for(int i=1;i<=n;i++){
   vector<int> v(n - 1); for(int &x: v) cin >> x;
   for(int j=1;j<n-1;j++){
    adj[v[j - 1]].push_back(v[j]);
    in[v[j]]++;
   }
  }
  
  for(int i=1;i<=n;i++) if(in[i] == 0) q.push(i);
  vector<int> topo;
  
  while(q.size()){
   int u = q.top(); q.pop();
   topo.push_back(u);
   for(int v: adj[u]){
    in[v]--;
    if(in[v] == 0) q.push(v);
   }
  }
  for(auto x: topo) cout << x << " "; cout << "\n";
 }
 return 0;
}