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
  int a[n + 5][n + 5];
  memset(a, 0, sizeof(a));
 
  for(int i=1;i<=n;i++){
   for(int j=1;j<=i;j++){
    if(j == 1 || j == i) cout << 1 << " ";
    else cout << 0 << " ";
   }
   cout << "\n";
  }
 }
 
 return 0;
}