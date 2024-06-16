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
 
int n, x1, Y1, x2, y2;
int mid;
int get(int x){
 if(x <= mid) return x;
 else return n - x + 1;
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  cin >> n >> x1 >> Y1 >> x2 >> y2;
  mid = n / 2;
  
  cout << abs(min(get(x1), get(Y1)) - min(get(x2), get(y2))) << "\n";
 }
 
 return 0;
}