#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
 
int p[maxn + 1], f[maxn + 1];
void sieve()
{
 for(int i=0;i<=maxn;i++) p[i] = 1;
 p[0] = p[1] = 0;
 for(int i=2;i<=sqrt(maxn);i++)
 {
  if(p[i] == 1) for(int j=i*i;j<=maxn;j+=i)
   p[j] = 0;   
 }
 for(int i=2;i<=maxn;i++)
 {
  f[i] = f[i - 1] + (p[i] == 1);
//  cout << f[i] << ' ';
 }
}
 
bool check(int m, int a, int b, int k)
{
 for(int i=a;i<=b-m+1;i++)
  if(f[i + m - 1] - f[i - 1] < k) return false;
 return true;
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 sieve();
 
 int a, b, k; cin >> a >> b >> k;
// cout << check(2, a, b, k);
 int l = 0, r = 1e6, ans = -1;
 while(l <= r)
 {
  int m = (l + r) / 2;
  if(check(m, a, b, k))
  {
   ans = m; r = m - 1;
  }
  else l = m + 1;
 }
 if(ans <= b - a + 1) 
  cout << ans;
 else cout << -1;
 return 0;
}