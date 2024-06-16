#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
#define pii pair<int,int> 
 
vector<int> adj[maxn + 1];
int l[maxn + 1], p[maxn + 1];
 
int n;
vector<int> v;
 
void inp(){
 cin >> n;
 for(int i=1;i<n;i++)
 {
  int x, y; cin >> x >> y;
  adj[x].push_back(y);
  adj[y].push_back(x);
 }
 for(int i=0;i<n;i++){
  int x; cin >> x;
  v.push_back(x);
 }
}
 
void lvlcalc(){
 queue<int> q;
 l[1] = 1;
 q.push(1);
 while(!q.empty())
 {
  int u = q.front(); q.pop();
  for(auto v: adj[u])
  {
   if(l[v]) continue;
   l[v] = l[u] + 1;
   p[v] = u;
   q.push(v);
  }
 }
}
 
//struct node{
// int level, par
//};
 
int pos[maxn + 1];
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 inp();
 lvlcalc();
 
 for(int i=1;i<n;i++){
  pos[v[i]] = i;
  if(l[v[i]] < l[v[i - 1]]) return cout << "No\n", 0;
 }
  
 
 vector<int> a = v;
 
 vector<pii> ans;
  
 for(int x: a){
  ans.push_back({l[x], p[x]});
 }
 
// for(auto x: ans) cout << x.first << ' '; cout << '\n';
// for(auto x: ans) cout << x.second << ' '; cout << '\n';
 
 for(int i=1;i<n;i++){
  if(ans[i].first == ans[i - 1].first 
   && pos[ans[i].second] < pos[ans[i - 1].second]) 
  return cout << "No\n", 0;
 }
 cout << "Yes\n";
 return 0;
}