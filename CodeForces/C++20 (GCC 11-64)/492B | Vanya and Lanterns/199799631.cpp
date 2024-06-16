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
 int n, l; cin >> n >> l;
 vector<int> a(n); for(int &i: a) cin >> i;
 sort(a.begin(), a.end());
 
 double ans = max(1.0*a[0], 1.0*l-a[n-1]);
 for(int i=1;i<n;i++){
  ans = max(ans, (1.0*a[i]-a[i-1])/2);
 }
 cout << fixed << setprecision(9) << ans;
 return 0;
}