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
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, m; cin >> n >> m;
  int a[m + 1]; 
  for(int i=1;i<=m;i++) cin >> a[i];
 
  deque<int> dq;
  for(int i=1;i<=n;i++) dq.push_back(i);
  
  int ok[n + m + 1]; memset(ok, 0, sizeof(ok));
  vector<int> ans(n + m + 1, -1);
  for(int i=1;i<=m;i++){
   if(ok[a[i]] == 0){
    ok[a[i]] = 1;
    ans[dq.back()] = i;
    dq.push_front(a[i]);
    dq.pop_back();
   }
  }    
  for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << "\n";
 }
 
 return 0;
}