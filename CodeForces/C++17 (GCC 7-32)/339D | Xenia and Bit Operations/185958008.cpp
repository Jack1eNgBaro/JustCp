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
 
int a[maxn + 1], sg[4 * maxn + 1], x = 123456789;
 
void build(int id, int rank, int l, int r){
 if(l == r){
  sg[id] = a[l];
//  cout << id << " " << rank << " " << sg[id] << "\n";
  return;
 }
 int m = (l + r) / 2;
 build(id * 2,     rank + 1, l, m);
 build(id * 2 + 1, rank + 1, m + 1, r);
 if((x + 2 - rank) % 2 == 1)
  sg[id] = sg[id * 2] ^ sg[id * 2 + 1];
 else
  sg[id] = sg[id * 2] | sg[id * 2 + 1];
// cout << id << " " << rank << " " << sg[id] << "\n";
}
 
void update(int id, int rank, int l, int r, int pos, int val){
 if(pos < l || pos > r) return;
 if(l == r){
  sg[id] = val;
  return;
 }
 int m = (l + r) / 2;
 update(id * 2,     rank + 1,     l, m, pos, val);
 update(id * 2 + 1, rank + 1, m + 1, r, pos, val);
 if((x + 2 - rank) % 2 == 1)
  sg[id] = sg[id * 2] ^ sg[id * 2 + 1];
 else
  sg[id] = sg[id * 2] | sg[id * 2 + 1];
}
 
main()
{
 file();
 int n, Q; cin >> n >> Q;
 x = n;
 n = (1 << n);
 for(int i=1;i<=n;i++) cin >> a[i];
 build(1, 1, 1, n);
// cout << sg[1] << "\n";
 while(Q--)
 {
  int pos, val; cin >> pos >> val;
  update(1, 1, 1, n, pos, val);
  cout << sg[1] << "\n";
 }
 
 return 0;
}