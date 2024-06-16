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
 
int main()
{
 file();
 int n, k; cin >> n >> k;
 deque<int> dq;
 for(int i=1;i<=n;i++){
  int x; cin >> x;
  dq.push_back(x);
 }
 
 int ans = 0;
 while(dq.size()){
  if(dq.front() <= k){
   ++ans; dq.pop_front();
  }else if(dq.back() <= k){
   ++ans; dq.pop_back();
  }else{
   break;
  }
 }
 cout << ans;
 return 0;
}