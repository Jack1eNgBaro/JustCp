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
 
 
int a, b, c;
int na, nb, nc;
int pa, pb, pc;
int r;
 
int kt(int mid){
 int ans = 0;
 int x = mid * a; x -= na;
 int y = mid * b; y -= nb;
 int z = mid * c; z -= nc;
 
 if(x >= 0)  ans += x*pa;
 if(y >= 0) ans += y*pb;
 if(z >= 0) ans += z*pc;
 return ans <= r;
}
 
main()
{
 file();
 string s; cin >> s;
 for(char x: s){
  if(x == 'B') a++;
  else if(x == 'S') b++;
  else if(x == 'C') c++;
 }
 cin >> na >> nb >> nc;
 cin >> pa >> pb >> pc;
 cin >> r;
 
 int l = 0, ans = 0, r = 1e15;
 while(l <= r){
  int m = (l + r) / 2;
  if(kt(m)){
   ans = m;
   l = m + 1;
  }else r = m - 1;
 }
 cout << ans;
 return 0;
}