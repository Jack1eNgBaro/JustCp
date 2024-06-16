/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
#define fi first
#define se second
#define vi vector<int> 
 
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
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  int a[n + 1];
  for(int i=1;i<=n;i++) cin >> a[i];
 
  int x = a[1] + a[n];
  if(x&1) x = a[1];
  else x = a[n];
  cout << n-1 << "\n";
  if(n>1) cout << 1 << ' ' << n << "\n";
  for(int i=2;i<n;i++){
   if((x+a[i])&1){
    cout << 1 << ' ' << i << "\n";
   }else{
    cout << i << ' ' << n << "\n";
   }
  }
 }
 
 return 0;
}