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
const int maxn = 505;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m;
int a[maxn + 1][maxn + 1];
int ok = 0;
 
void sol(){
 for(int i=2;i<=n;i++){
  for(int j=2;j<=m;j++){
   if(a[i][j] == 0) continue;
   int x = a[i-1][j] + a[i][j-1] + a[i][j+1] + a[i+1][j] + a[i][j];
   if(ok == 0 && x == 5){
    ok = 1; 
    
    a[i][j] = 0;
    for(int k=i+1;k<=n&&a[k][j]==1;k++) a[k][j] = 0;
    for(int k=i-1;k>=1&&a[k][j]==1;k--) a[k][j] = 0;
    
    for(int k=j+1;k<=m&&a[i][k]==1;k++) a[i][k] = 0;
    for(int k=j-1;k>=1&&a[i][k]==1;k--) a[i][k] = 0; 
    
    return;
   }
  }
 }
}
 
int main()
{
 file();
 cin >> n >> m;
 if(n < 3 && m < 3) return cout << "NO\n", 0;
 for(int i=1;i<=n;i++){
  for(int j=1;j<=m;j++){
   char x; cin >> x;
   if(x == '*') a[i][j] = 1;
  }
 }
 sol();
 if(ok){
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]) return cout << "NO\n",0;
  cout << "YES\n";
 }else{
  cout << "NO\n";
 }
 
 return 0;
}