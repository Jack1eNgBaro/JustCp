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
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  int n, k; cin >> n >> k;
  if(k == 1 || k == n){
   for(int i=1;i<=n;i++) cout << i << ' ';
   cout << "\n";
   continue;
  }
  
  vector<int> a(n + 1, 0), ok(n + 1, 0);
  int x = n, mx = n + 1;
  
  for(int i=1;i<=n;i++)
  {
   if(a[i] == 0)
   {
    while(ok[x]) --x;
    a[i] = x;
    ok[x] = 1;
   }
   
   if(i + k - 1 <= n)
   {
    int t = mx - a[i];
    while(ok[t]) --t;
    a[i + k - 1] = t;
    ok[t] = 1;
   }
  }
  for(int i=1;i<=n;i++) cout << a[i] << ' '; cout << "\n";
 }
 return 0;
}