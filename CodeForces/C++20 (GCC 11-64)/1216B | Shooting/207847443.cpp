/*
  The only thing we have to fear is fear itself.
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
 
struct ele{
 int val, id;
};
int cmp(ele a, ele b){
 return a.val > b.val;
}
ele a[maxn + 1];
 
int main()
{
 file();
 int n; cin >> n;
 for(int i=1;i<=n;i++){
  cin >> a[i].val;
  a[i].id = i;
 }
 sort(a + 1, a + n + 1, cmp);
 vector<int> v;
 int ans = 0;
 for(int i=1;i<=n;i++){
  ans += (a[i].val * (i - 1)) + 1;
  v.push_back(a[i].id);
 }
 cout << ans << "\n";
 for(auto x: v) cout << x << ' ';
 return 0;
}