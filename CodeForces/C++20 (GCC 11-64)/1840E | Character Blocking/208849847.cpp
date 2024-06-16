/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
#define fi first
#define se second
#define vi vector<int> 
 
const int mod = 1e9 + 7;
const int maxn = 2e5;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
string s[3];
int sg[4*maxn+1], tg[2*maxn+1];
int quer[4*maxn + 1];
 
void build(int id, int l, int r){
 if(l == r){
  sg[id] = (s[1][l] != s[2][r]);
  return;
 }
 int m = (l + r) / 2;
 build(id*2, l, m);
 build(id*2+1, m+1, r);
 sg[id] = (sg[id*2] + sg[id*2+1]);
}
 
void block(int id, int l, int r, int pos){
 if(pos<l||pos>r) return;
 if(l==r) return sg[id] = 0, void();
 int m = (l+r)/2;
 block(id*2, l, m, pos);
 block(id*2+1, m+1, r, pos);
 sg[id] = (sg[id*2] + sg[id*2+1]);
}
 
void update(int id, int l, int r, int pos){
 if(pos<l||pos>r) return;
 if(l == r){
  sg[id] = (s[1][l] != s[2][r]); return;
 }
 int m = (l + r) / 2;
 update(id*2, l, m, pos);
 update(id*2+1, m+1, r, pos);
 sg[id] = (sg[id*2] + sg[id*2+1]);
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  memset(tg, 0, sizeof(tg));
  cin >> s[1] >> s[2];
 
  int n = s[1].size();
 
  s[1] = "~" + s[1];
  s[2] = "~" + s[2];
 
  build(1, 1, n);
  int blocktime, q; cin >> blocktime >> q;
  for(int i=1;i<=q;i++){
   int type; cin >> type;
   if(tg[i] == 1){
    update(1, 1, n, quer[i - blocktime]);
   }
   if(type == 1){
    int pos; cin >> pos;
    block(1, 1, n, pos);
    tg[i + blocktime] = 1;
    quer[i] = pos;
   }else if(type == 2){
    int id1, id2, pos1, pos2; cin >> id1 >> pos1 >> id2 >> pos2;
    swap(s[id1][pos1], s[id2][pos2]);
    update(1, 1, n, pos1);
    update(1, 1, n, pos2);
   }else{
    if(sg[1] == 0) cout << "YES\n";
    else cout << "NO\n";
   }
  }
 }
 
 return 0;
}