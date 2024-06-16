/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int maxn = 2e5;
const int mod = 1e9 + 7;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, k;
int a[maxn + 1];
 
int cnt[maxn + 1];
main()
{
 file();
 cin >> n >> k;
 vector<int> v;
 for(int i=1;i<=n;i++){
  cin >> a[i];
  v.push_back(a[i]);
 }
 while(k--){
  int x, y; cin >> x >> y;
  if(a[x] > a[y]) cnt[x]++;
  else if(a[y] > a[x]) cnt[y]++;
 }
 
 sort(v.begin(), v.end());
 for(int i=1;i<=n;i++){
  auto it = lower_bound(v.begin(), v.end(), a[i]);
  int ans = it - v.begin() - cnt[i];
  cout << max(0ll, ans) << " ";
 }
 return 0;
}