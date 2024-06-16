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
 
int n, m;
struct exam{
 int s, d, c, id; 
};
exam a[maxn + 1];
 
int cmp(exam a, exam b){
 return a.d < b.d;
}
 
int main()
{
 file();
 cin >> n >> m;
 set<int> se;
 for(int i=1;i<=m;i++){
  cin >> a[i].s >> a[i].d >> a[i].c;
  a[i].id = i;
  se.insert(a[i].d);
 }
 vector<int> ans(n + 1, 0);
 for(auto x: se) ans[x] = m + 1;
 sort(a + 1, a + m + 1, cmp);
 for(int i=1;i<=m;i++){
  int cnt = 0;
  for(int j=a[i].s;j<a[i].d;j++){
   if(cnt == a[i].c) break;
   if(ans[j] == 0){
    ans[j] = a[i].id;
    ++cnt;
   }
  }
  if(cnt < a[i].c) return cout << "-1\n", 0;
 }
 for(int i=1;i<=n;i++) cout << ans[i] << ' ';
 return 0;
}