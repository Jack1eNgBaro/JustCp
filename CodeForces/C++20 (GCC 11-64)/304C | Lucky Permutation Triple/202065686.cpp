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
// ios_base::sync_with_stdio(0);
// cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n; 
void test(){
 vector<int> v;
 for(int i=0;i<n;i++) v.push_back(i);
 vector<vector<int>> a;
 do{
  a.push_back(v);
 }while(next_permutation(v.begin(), v.end()));
 for(auto x: a){
  for(auto y: a){
   for(auto z: a){
    int ok = 1;
    for(int i=0;i<n;i++){
     if((x[i] + y[i]) % n != z[i] % n) ok = 0;
    }
    if(ok){
     for(auto i: x) cout << i << ' '; cout << "\n";
     for(auto i: y) cout << i << ' '; cout << "\n";
     for(auto i: z) cout << i << ' '; cout << "\n";
     cout << "\n";
    }
   }
  }
 }
}
int main()
{
 file();
 cin >> n;
 if(n == 1) cout << "0\n0\n0\n";
 else if(n&1){
  vector<int> a(n), b(n), c(n);
  for(int i=0;i<n;i++) a[i] = i;
  for(int i=n-1;i>=0;i--) c[n-i-1] = i;
  for(int i=0;i<n;i++){
   int x = c[i] - a[i];
   b[i] = ((x + n) % n);
  }
  for(auto x: a) cout << x << ' '; cout << "\n";
  for(auto x: b) cout << x << ' '; cout << "\n";
  for(auto x: c) cout << x << ' '; cout << "\n";
 }else cout << "-1\n";
// test();
 return 0;
}