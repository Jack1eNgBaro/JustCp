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
 
vector<int> v;
void init(){
 int d = 0;
 for(int i=0;i<=1e5;i++){
  v.push_back(i * (i + 1) / 2);
 }
}
 
void solve(int n, int k){
 string s(n, 'a');
// int d=0;while(d*(d+1)/2 < k) ++d;
 int d = lower_bound(v.begin(), v.end(), k) - v.begin();
 s[n - d - 1] = 'b'; 
// cout << s << "\n";
 int x = k - (d-1)*d/2;
// cout << n - x - 1 << "\n";
 s[n - x] = 'b';
 cout << s << "\n";
}
 
main()
{
 file();
 int tc; cin >> tc;
 init();
 while(tc--){
  int a, b; cin >> a >> b;
  solve(a, b);
 }
 return 0;
}