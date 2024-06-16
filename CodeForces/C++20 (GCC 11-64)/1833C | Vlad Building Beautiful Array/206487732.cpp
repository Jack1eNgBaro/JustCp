/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
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
 
int main()
{
 file();
 int tc = 1;
   cin >> tc;
 while(tc--){
  int n; cin >> n;
  int a[n];
  vector<int> c, l;
  for(int &i: a){
   cin >> i;
   if(i&1) l.push_back(i);
   else c.push_back(i);
  }
  sort(c.begin(), c.end());
  sort(l.begin(), l.end());
  
  vector<int> ans(n, -1), res(n, -1);
  
  int ok = 1, ko = 1;
  for(int i=0;i<n;i++){
   int x = a[i];
   if(x&1){
    ans[i] = x;
   }else{
    auto it = lower_bound(l.begin(), l.end(), x);
    if(it == l.begin()){
     ok = 0; break;
    }
   }
  }
  
  for(int i=0;i<n;i++){
   int x = a[i];
   if(x%2==0){
    res[i] = x;
   }else{
    auto it = lower_bound(l.begin(), l.end(), x);
    if(it == l.begin()){
     ko = 0; break;
    }
   }
  }
  if(ok || ko) cout << "YES\n";
  else cout << "NO\n";
 }
 
 return 0;
}