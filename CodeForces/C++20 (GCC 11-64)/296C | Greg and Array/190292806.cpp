#include<bits/stdc++.h>
using namespace std;
 
#define int unsigned long long
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
 
int n, m, q;
struct oper{
 int l, r, d; 
};
int a[maxn + 1], cnt[maxn + 1], f[maxn + 1];
 
oper v[maxn + 1];
main()
{
 file();
 cin >> n >> m >> q;
 for(int i=1;i<=n;i++) cin >> a[i];
 for(int i=1;i<=m;i++){
  int x, y, z; cin >> x >> y >> z;
  v[i] = {x, y, z};
 }
 while(q--){
  int l, r; cin >> l >> r;
  cnt[l]++;
  cnt[r + 1]--;
 }
 for(int i=1;i<=maxn;i++){
  cnt[i] += cnt[i - 1];
//  cout << cnt[i] << " ";
 }
 
 for(int i=1;i<=m;i++){
  f[v[i].l] += (v[i].d * cnt[i]);
  f[v[i].r + 1] -= (v[i].d * cnt[i]);
 }
 for(int i=1;i<=n;i++){
  f[i] += f[i - 1];
  cout << a[i] + f[i] << ' ';
 }
 return 0;
}