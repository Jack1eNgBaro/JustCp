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
const int maxn = 1e6;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
void solve(){
 int n; cin >> n;
 int ans = -1;
 
 int a[n]; for(int &i: a) cin >> i;
 
 for(int x=0;x<256;x++){
  int b[n];
  for(int i=0;i<n;i++) b[i] = a[i] ^ x;
  int s = b[0];
  for(int i=1;i<n;i++) s ^= b[i];
  if(s == 0) return cout << x << "\n", void();
 }
 cout << "-1\n";
}
 
int main()
{
 file(); 
 int tc; cin >> tc;
 while(tc--){
  solve();  
 }
 return 0;
}