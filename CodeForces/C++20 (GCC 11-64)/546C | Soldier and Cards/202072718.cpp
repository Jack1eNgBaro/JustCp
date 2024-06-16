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
#define dqe deque<int>
 
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
 
 int n; cin >> n;
 set<pair<dqe,dqe>> se;
 dqe a, b;
 
 int db, rr; cin >> db;
 while(db--){
  int x; cin >> x;
  a.push_back(x);
 }
 cin >> rr;
 while(rr--){
  int x; cin >> x;
  b.push_back(x);
 }
 
// for(auto x: a) cout << x << ' '; cout << "\n";
// for(auto x: b) cout << x << ' '; cout << "\n";
// cout << "\n";
 se.insert({a, b});
 int ans = 0;
 while(a.size() && b.size()){
  
//  for(auto x: a) cout << x << ' '; cout << "\n";
//  for(auto x: b) cout << x << ' '; cout << "\n";
//  cout << "\n";
  
  int x = a.front(); a.pop_front(); 
  int y = b.front(); b.pop_front();
  
  if(x > y){
   a.push_back(y);
   a.push_back(x);
  }else{
   b.push_back(x);
   b.push_back(y);
  }
  if(se.count({a, b})){
   cout << "-1\n"; return 0;
  }
  se.insert({a, b});
  ++ans;
 }
 int res;
 if(a.size()) res = 1;
 else res = 2;
 cout << ans << ' ' << res;
 return 0;
}