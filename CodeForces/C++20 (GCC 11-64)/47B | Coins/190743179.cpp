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
 
int in[maxn + 1];
vector<int> adj[maxn + 1];
 
int main()
{
 file();
 for(int i=0;i<3;i++){
  char x, y, z; cin >> x >> y >> z;
  if(y == '>'){
   adj[z - 'A'].push_back(x - 'A');
   in[x - 'A']++;
  }else{
   adj[x - 'A'].push_back(z - 'A');
   in[z - 'A']++;
  }
 }
 queue<int> q;
 for(int i=0;i<3;i++) if(in[i] == 0) q.push(i);
 vector<int> topo;
 while(q.size()){
  int u = q.front(); q.pop();
  topo.push_back(u);
  for(int v: adj[u]){
   in[v]--;
   if(in[v] == 0) q.push(v);
  }
 }
 if(topo.size() == 3) for(auto x: topo) cout << (char)('A' + x);
 else cout << "Impossible\n";
 return 0;
}