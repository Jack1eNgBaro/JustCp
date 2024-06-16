/*
  The only thing we have to fear is fear itself.
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
 
int Powf(int a, int b){
 int ans = 1;
 while(b){
  if(b&1) ans = (ans * a);
  a = a * a;
  b >>= 1;
 }
 return ans;
}
 
vector<int> v;
void init(){
 v.push_back(1);
 for(int i=1;Powf(2, i) <= 1e9;i++){
  v.push_back(v[i - 1] + Powf(2, i));
 }
}
main()
{
 file();
 init();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  for(int i=1;i<v.size();i++){
   if(n % v[i] == 0){
//    cout << v[i] << " " << n / v[i] << ' ';
    cout << n / v[i] << "\n";
    break;
   }
  }
 }
 
 return 0;
}