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
 int n; cin >> n;
 deque<char> dq;
 
 int x = n % 2;
 
 for(int i=1;i<=n;i++){
  char c; cin >> c;
  if(x == 0){
   if(i % 2 == 0) dq.push_back(c);
   else dq.push_front(c);
  }else{
   if(i % 2 == 1) dq.push_back(c);
   else dq.push_front(c);
  }
 }
 for(auto x: dq) cout << x;
 return 0;
}