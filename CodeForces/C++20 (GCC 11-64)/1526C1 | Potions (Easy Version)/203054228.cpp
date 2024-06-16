#include<bits/stdc++.h>
using namespace std;
#define int long long
 
main(){
// freopen("Input.inp", "r", stdin);
// freopen("Output.out", "w", stdout);
 int n; cin >> n;
 int s = 0, ans = 0;
 
 priority_queue<int, vector<int>, greater<int>> q;
 
 for(int i=1;i<=n;i++){
  int x; cin >> x;
  s += x;
  q.push(x);
  
  if(s < 0){
   s -= q.top();
   q.pop();
  }
 }
 cout << q.size();
 return 0;
}