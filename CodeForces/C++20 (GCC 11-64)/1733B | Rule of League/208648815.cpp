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
  int n, x, y; cin >> n >> x >> y;
  if(x > y) swap(x, y);
  if(x > 0 && y > 0 || x+y==0){
   cout << "-1\n";
  }else if(x == 0 && y > 0){
   --n;
   if(n % y > 0) cout << "-1\n";
   else{
    int win = 1, cnt = 0;
    for(int i=2;i<=n+1;i++){
     if(cnt < y){
      ++cnt;
     }else{
      win = i; cnt = 1;
     }
     cout << win << ' ';
    }
    cout << "\n";
   }
  }
 }
 
 return 0;
}