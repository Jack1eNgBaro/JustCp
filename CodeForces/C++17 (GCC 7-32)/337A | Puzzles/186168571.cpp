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
 int k, n; cin >> k >> n;
 int a[n + 1]; for(int i=1;i<=n;i++) cin >> a[i];
 sort(a + 1, a + n + 1);
 
 multiset<int> ms;
 for(int i=1;i<=k;i++) ms.insert(a[i]);
 
 int ans = *ms.rbegin() - *ms.begin();
 for(int i=2;i<=n-k+1;i++)
 {
  ms.erase(ms.find(a[i - 1]));
  ms.insert(a[i + k - 1]);
  ans = min(ans, *ms.rbegin() - *ms.begin());
 }
 cout << ans << "\n";
 return 0;
}