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
 
vector<int> gene(int a, int b, int c){
 vector<int> v = {a, b, c, a + b, a + c, b + c, a + b + c};
 sort(v.begin(), v.end());
 return v;
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  vector<int> a(7); for(int &i: a) cin >> i;
  int x = a[0], s = a[6];
  for(int i=1;i<5;i++){
   int y = a[i] - x;
   int z = s - x - y;
   if(gene(x, y, z) == a){
    cout << x << ' ' << y << ' ' << z << "\n"; break;
   }
  }  
 }
 
 return 0;
}