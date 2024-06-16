#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 26;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
char tochar(int x){
 char ans = 'a';
 ans += x;
 return ans;
}
 
int toint(char a){
 return a - 'a';
}
 
int n, ok = 1, in[maxn + 1];
string a[105 + 1];
vector<int> adj[maxn + 1];
 
int main()
{
 file();
 cin >> n;
 for(int i=1;i<=n;i++) cin >> a[i];
 
 for(int i=2;i<=n;i++)
 {
  string s = a[i - 1];
  string t = a[i];
  int x = min(s.size(), t.size());
  int id = 0;
  while(id < x && s[id] == t[id]) ++id;
  if(id < x){
   adj[toint(s[id])].push_back(toint(t[id]));
   in[toint(t[id])]++;
  }
  else{
   if(s.size() > t.size()){
    ok = 0;
   }
  }
 }
 
 priority_queue<int, vector<int>, greater<int>> q;
 for(int i=0;i<maxn;i++){
  if(in[i] == 0) q.push(i);
 }
 
 vector<int> topo;
 while(q.size())
 {
  int u = q.top(); q.pop();
  topo.push_back(u);
  for(int v: adj[u])
  {
   in[v]--;
   if(in[v] == 0) q.push(v);
  }
 } 
 if(ok && topo.size() == 26)
  for(auto x: topo) cout << tochar(x);
 else cout << "Impossible\n";
 return 0;
}