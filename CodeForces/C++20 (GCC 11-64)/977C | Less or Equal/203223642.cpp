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
 
int main()
{
 file();
 int n, k; cin >> n >> k;
 vector<int> a(n); 
 for(int &i: a) cin >> i;
 sort(a.begin(), a.end());
 
// for(auto x: a) cout << x << ' '; cout << '\n';
 
 int l = 1, r = 1e9;
 while(l <= r){
  int m = (l + r) / 2;
  auto it = upper_bound(a.begin(), a.end(), m);
  int x = it - a.begin();
  if(x > k){
   r = m - 1;
  }else if(x < k){
   l = m + 1;
  }else{
   return cout << m, 0;
  }
 }
 cout << -1;
 return 0;
}