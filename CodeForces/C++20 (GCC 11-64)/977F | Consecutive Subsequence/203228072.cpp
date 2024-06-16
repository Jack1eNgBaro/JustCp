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
const int maxn = 2e5;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
map<int,int> mp;
int f[maxn + 1], g[maxn + 1], trace[maxn + 1];
int main()
{
 file();
 int n; cin >> n;
 int a[n + 1];
 for(int i=1;i<=n;i++){
  cin >> a[i];
  if(mp.count(a[i] - 1)){
   g[i] = mp[a[i] - 1];
  }else{
   g[i] = 0;
  }
  mp[a[i]] = i;
 }
 
 for(int i=1;i<=n;i++){
  if(g[i] == 0){
   f[i] = 1;
  }else{
   f[i] = f[g[i]] + 1;
   trace[i] = g[i];
  }
 }
 
 int mx = 0, s = 0;
 for(int i=1;i<=n;i++){
  if(f[i] > mx){
   mx = f[i];
   s = i;
  }
 }
 
 cout << mx << "\n";
 vector<int> go;
 while(s != 0){
  go.push_back(s);
  s = trace[s];
 }
 reverse(go.begin(), go.end());
 for(auto x: go) cout << x << ' ';
 return 0;
}