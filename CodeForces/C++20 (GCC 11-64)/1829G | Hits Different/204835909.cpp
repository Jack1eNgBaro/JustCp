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
const int maxn = 205;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
vector<int> v;
vector<int> a[1505], f[1505];
main()
{
 file();
 
 int cnt = 1;
// f[0] = vector<int>(1, 0);
 for(int i=1;i<=1500;i++){
  a[i] = vector<int>(i + 1, 0);
  f[i] = vector<int>(i + 1, 0);
  for(int j=1;j<=i;j++){
   a[i][j] = cnt;
   int x = cnt * cnt;
   if(i == 1){
    f[i][j] = 1; 
    ++cnt;
    continue;
   }
   if(j == 1){
    f[i][j] = f[i - 1][j] + x;
   }
   else if(j == i){
    f[i][j] = f[i - 1][j - 1] + x;
   }
   else{
    f[i][j] = f[i - 1][j - 1] + f[i - 1][j] + x;
    f[i][j] -= f[i - 2][j - 1];
   }
   ++cnt;
  }
 }
 
 for(int i=0;i<=1500;i++){
  v.push_back(i*(i+1)/2);
 }
 
 int tc = 1; 
  cin >> tc;
 while(tc--){
  int n; cin >> n;
  auto it = lower_bound(v.begin(), v.end(), n);
//  --it;   
  int x = it - v.begin();
//  cout << x << "\n";
  int y = n - (x-1)*x/2;
//  int n; cin >> n;
//  for(int i=1;i<=n;i++){
//   for(int j=1;j<=i;j++) cout << f[i][j] << " ";
//   cout << "\n";
//  }
  cout << f[x][y] << "\n";
 }
 return 0;
}