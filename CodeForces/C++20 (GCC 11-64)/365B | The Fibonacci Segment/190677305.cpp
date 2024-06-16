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
 
int a[maxn + 1];
int main()
{
 file();
 int n; cin >> n;
 for(int i=1;i<=n;i++) cin >> a[i];
 
 if(n == 1 || n == 2) return cout << n, 0;
 
 int ans = 2, cnt = 2;
 for(int i=3;i<=n;i++){
  if(a[i] == a[i - 2] + a[i - 1]){
   ++cnt;
  }
  else cnt = 2;
  ans = max(ans, cnt);
 }
 cout << ans;
 return 0;
}