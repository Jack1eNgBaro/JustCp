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
 
int main()
{
 file();
 int n, k, t; cin >> n >> k >> t;
 int a[n + 1] = {0};
 t = n*k*t/100;
 int s = t/k;
 for(int i=1;i<=s;i++) a[i] = k;
 a[s + 1] = t % k;
 for(int i=1;i<=n;i++) cout << a[i] << " ";
 return 0;
}