#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
main()
{
 file();
 int n; cin >> n;
 int a[n + 1], b[n + 1]; 
 for(int i=1;i<=n;i++){
  cin >> a[i];
  b[i] = a[i];
 }
 sort(b + 1, b + n + 1);
 vector<int> u(n + 1, 0), v(n + 1, 0);
 for(int i=1;i<=n;i++){
  u[i] = u[i - 1] + a[i];
  v[i] = v[i - 1] + b[i];
 }
 
 int q; cin >> q;
 while(q--)
 {
  int t, l, r; cin >> t >> l >> r;
  if(t == 2){
   cout << v[r] - v[l - 1] << "\n";
  }else{
   cout << u[r] - u[l - 1] << "\n";
  }
 }
 
 return 0;
}