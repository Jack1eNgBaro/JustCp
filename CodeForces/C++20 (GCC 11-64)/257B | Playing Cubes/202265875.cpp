/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
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
 
int ans, res;
void go(vector<int> a){
 int s = 0, t = 0;
 for(int i=1;i<a.size();i++){
  if(a[i] == a[i - 1]) ++s;
  else ++t;
 }
 if(s > ans || t > res){
  ans = s;
  res = t;
 }
}
 
int n, m, sz;
void db(vector<int> &a, int t){
 int cnt[2];
 cnt[0] = n;
 cnt[1] = m;
 
 a[0] = t; cnt[t]--;
 for(int i=1;i<sz;i++){
  if(i&1){
   int x = 1 - a[i - 1];
   if(cnt[x] > 0){
    --cnt[x]; a[i] = x;
   }else{
    --cnt[1 - x]; a[i] = 1 - x;
   }
  }else{
   int x = a[i - 1];
    if(cnt[x] > 0){
    --cnt[x]; a[i] = x;
   }else{
    --cnt[1 - x]; a[i] = 1 - x;
   }
  }
 }
 
}
 
int main()
{
 file();
 cin >> n >> m;
 sz = n + m;
 vector<int> a(sz), b(sz);
 db(a, 0);
 db(b, 1);
// for(auto x: a) cout << x; cout << "\n";
// for(auto x: b) cout << x; cout << "\n";
 
 pii ans = {-1, -1};
 int db = 0, rr = 0;
 for(int i=1;i<sz;i++){
  if(a[i] == a[i - 1]) ++db;
  else ++rr;
 }
 if(db > ans.first){
  ans = {db, rr};
 }
 
 db = 0, rr = 0;
 for(int i=1;i<sz;i++){
  if(b[i] == b[i - 1]) ++db;
  else ++rr;
 }
 if(db > ans.first){
  ans = {db, rr};
 }
 cout << ans.first << ' ' << ans.second;
 return 0;
}