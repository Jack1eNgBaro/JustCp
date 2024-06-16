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
 
int n, w, h;
int a[maxn + 1], b[maxn + 1];
 
int fun(int m){
 for(int i=1;i<=n;i++){
  if(b[i] - h < a[i] - w + m) return -1;
  if(b[i] + h > a[i] + w + m) return 1;
 }
 return 0;
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  cin >> n >> w >> h;
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=1;i<=n;i++) cin >> b[i];
  
  int l = -1e9, r = 1e9, ans = 0;
  while(l <= r){
   int m = (l + r) / 2;
   int t = fun(m);
   if(t == 0){
    ans = 1;
    r = m - 1;
    break;
   }
   else if(t == -1) r = m - 1;
   else l = m + 1;
  }
  if(ans) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}