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
 int n, k; cin >> n >> k;
 int ans = 0;
 while(n--){
  int x; cin >> x;
  if(x > k) ans += 2;
  else ans += 1;
 }
 cout << ans;
 return 0;
}