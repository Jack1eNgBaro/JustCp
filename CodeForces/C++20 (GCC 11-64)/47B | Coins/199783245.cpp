/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 4;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int in[maxn+1];
vector<int> adj[maxn+1];
 
int main()
{
 file();
 for(int i=0;i<3;i++){
  char x, z, y; cin >> x >> z >> y;
  if(z == '>') {adj[y-'A'].push_back(x-'A'); in[x-'A']++;}
  else {adj[x-'A'].push_back(y-'A'); in[y-'A']++;}
 }
 
 queue<int> q;
 for(int i=0;i<3;i++) if(in[i] == 0) q.push(i);
 vector<int> topo;
 while(q.size()){
  int u = q.front(); q.pop();
  topo.push_back(u);
  for(auto v: adj[u]){
   in[v]--;
   if(in[v] == 0){
    q.push(v);
   }
  }
 }
 if(topo.size() == 3){
  for(auto x: topo) cout << (char)('A'+x);  
 }
 else cout << "Impossible";
 return 0;
}