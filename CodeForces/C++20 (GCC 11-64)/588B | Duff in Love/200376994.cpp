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
 
int scp(int n){
 int x = sqrt(n);
 return x*x == n;
}
 
vector<int> go(int n){
 vector<int> v;
 v.push_back(n);
 for(int i=2;i<=sqrt(n);i++){
  if(n % i == 0){
   v.push_back(i);
   if(i * i != n) v.push_back(n / i);
  }
 }
 return v;
}
 
main()
{
 file();
 int n; cin >> n;
 auto v = go(n);
 
 sort(v.begin(), v.end(), greater<int>());
 for(int i=0;i<v.size();i++){
//  cout << v[i] << ' ';
  auto a = go(v[i]);
  int ok = 1;
  for(auto x: a){
   if(scp(x)){
    ok = 0;
    break;
   }
  }
  if(ok) return cout << v[i], 0;
 }
 cout << 1;
 return 0;
}