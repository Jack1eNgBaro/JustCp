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
 int ans = 0;
 int n, k; cin >> n >> k;
 while(n--){
  vector<int> ok(10, 0);
  int x; cin >> x;
  while(x){
   int r = x % 10;
   ok[r] = 1;
   x /= 10;
  }
  int cnt = 0;
  for(int i=0;i<=k;i++) cnt += ok[i];
  ans += (cnt == k + 1);
 }
 cout<< ans;
 return 0;
}