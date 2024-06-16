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
 
void solve(){
 int n; cin >> n;
 set<int> ok, ko;
 int a[n + 1]; for(int i=1;i<=n;i++){
  cin >> a[i];
  ok.insert(i);
  ko.insert(i);
 }
 
 int p[n + 1], q[n + 1];
 memset(p, 0, sizeof(p));
 memset(q, 0, sizeof(q));
 
 
 for(int i=1;i<=n;i++){
  int x = a[i];
  if(ok.count(x)){
   q[i] = x; 
   ok.erase(x);
  }
  else if(ko.count(x)){
   p[i] = x;
   ko.erase(x);
  }
  else{
   cout << "NO\n"; return;
  }
 }
 
 for(int i=1;i<=n;i++){
  if(q[i] == 0 && p[i] != 0){
   auto it = ok.upper_bound(p[i]);
   if(it == ok.begin()){
    cout << "NO\n"; return;
   }
   --it;
   q[i] = *it;
   ok.erase(it);
  }
  else if(q[i] != 0 && p[i] == 0){
   auto it = ko.upper_bound(q[i]);
   if(it == ko.begin()){
    cout << "NO\n"; return;
   }
   --it;
   p[i] = *it;
   ko.erase(it);
  }
 }
 
 
  cout << "YES\n";
  for(int i=1;i<=n;i++) cout << p[i] << " "; cout << "\n";
  for(int i=1;i<=n;i++) cout << q[i] << " "; cout << "\n";
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  
  solve();
 }
 return 0;
}