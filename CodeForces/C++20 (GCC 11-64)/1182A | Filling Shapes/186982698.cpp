#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
main()
{
 file();
 int n; cin >> n;
 vector<int> f(n + 1, 0);
 f[0] = 1;
 for(int i=2;i<=n;i+=2){
  f[i] = 2 * f[i - 2];
 }
 cout << f[n];
 return 0;
}
 