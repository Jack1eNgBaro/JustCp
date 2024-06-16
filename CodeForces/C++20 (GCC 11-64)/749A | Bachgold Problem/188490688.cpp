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
  
 vector<int> ans;
 if(n % 2 == 1){
  ans.push_back(3);
  n -= 3;
 }
 while(n && n % 2 == 0){
  ans.push_back(2);
  n -= 2;
 }
 
 cout << ans.size() << "\n";
 for(auto x: ans) cout << x << " ";
 return 0;
}