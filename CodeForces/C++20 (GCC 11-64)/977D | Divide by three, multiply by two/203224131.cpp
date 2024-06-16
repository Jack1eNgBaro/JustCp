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
 
int in[maxn + 1];
vector<int> adj[maxn + 1];
 
main()
{
 file();
 int n; cin >> n;
 int a[n + 1];
 for(int i=1;i<=n;i++) cin >> a[i];
 sort(a + 1, a + n + 1);
 
 for(int i=1;i<=n;i++){
  for(int j=i+1;j<=n;j++){
   if(a[i] * 3 == a[j]){
    adj[j].push_back(i);
    in[i]++;
   }
   if(a[i] * 2 == a[j]){
    adj[i].push_back(j);
    in[j]++;
   }
  }
 }
 
 queue<int> q;
 for(int i=1;i<=n;i++){
  if(in[i] == 0) q.push(i);
 }
 
 vector<int> topo;
 while(q.size()){
  int u = q.front(); q.pop();
  topo.push_back(u);
  for(int v: adj[u]){
   in[v]--;
   if(in[v] == 0) q.push(v);
  }
 }
 for(auto x: topo) cout << a[x] << ' ';
 
 return 0;
}