#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 1e6;
 
int kt(int n){
 int cnt = 0;
 while(n){
  int r = n % 10;
  if(r != 0) ++cnt;
  n /= 10;
 }
 return cnt == 1;
}
int f[maxn + 1];
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 for(int i=1;i<=maxn;i++){
  f[i] = f[i - 1] + (kt(i) == 1);
 }
 
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  cout << f[n] << "\n";
 }
   
 return 0;
}