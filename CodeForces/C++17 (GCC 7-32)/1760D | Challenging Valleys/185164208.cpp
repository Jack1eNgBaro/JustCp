#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  vector<int> a;
  for(int i=0;i<n;i++)
  {
   int x; cin >> x;
   if(a.empty() || x != a.back())
    a.push_back(x);
  }
  
  if(a.size() == 1){
   cout << "YES\n";
  }
  else{
   int ans = 0;
   n = a.size();
   for(int i=0;i<n;i++)
   {
    if(i == 0 && a[i + 1] > a[i]) ++ans;
    else if(i == n - 1 && a[n - 2] > a[i]) ++ans;
    else if(a[i - 1] > a[i] && a[i + 1] > a[i]) ++ans;
   }
   if(ans == 1 ) cout << "YES\n";
   else cout << "NO\n";
  }
 }
   
 return 0;
}