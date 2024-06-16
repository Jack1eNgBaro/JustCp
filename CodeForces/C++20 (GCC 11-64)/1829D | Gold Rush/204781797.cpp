/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, m; cin >> n >> m;
  if(m > n) cout << "NO\n";
  else if(n == m) cout << "YES\n";
  else{
   int ok = 0;
   queue<int> q;
   if(n % 3 == 0) q.push(n);
   while(!q.empty()){
    int u = q.front(); q.pop();
    if(u == m){
     ok = 1;
     break;
    }
    if(u && u % 3 == 0){
     q.push(u / 3);
     q.push(u / 3 * 2);
    }
   }
   if(ok) cout << "YES\n";
   else cout << "NO\n";
  }
 }
 return 0;
}