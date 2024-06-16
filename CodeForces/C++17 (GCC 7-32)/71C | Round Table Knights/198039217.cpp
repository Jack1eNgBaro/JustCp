/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
/*
ID: nbaro242
PROG: 
LANG: C++11
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
 
int n, a[maxn + 1];
vector<int> b;
int kt(int m){
 if(n / m < 3) return 0;
 for(auto x: b){
  int ok = 1;
//  cout << m << ": ";
  for(int i=0;i<n/m;i++){
   int y = x + i*m;
//   cout << y << ' ';
   if(y > n || a[y] == 0){
    ok = 0; break;
   }
  }
//  cout << "\n";
  if(ok) return 1;
 }
 return 0;
}
int main()
{
 file();
 cin >> n;
 for(int i=1;i<=n;i++){
  cin >> a[i];
  if(a[i] == 1){
   b.push_back(i);
  }
 }
 
 vector<int> v;
 for(int i=1;i<=sqrt(n);i++){
  if(n % i == 0){
   v.push_back(i);
   v.push_back(n/i);
  }
 }
 
 for(auto x: v){
  if(kt(x)){
   cout << "YES\n"; return 0;   
  }
 }
 cout << "NO\n";
 return 0;
}