#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
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
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  string a; cin >> a;
  a = "~" + a;
  
  int l = 1, r = n;
  while(l <= r && a[l] != a[r]){
   ++l;
   --r;
  }
//  cout << l << ' ' << r << "\n";
  cout << max(0, r - l + 1) << "\n";
 }
 return 0;
}