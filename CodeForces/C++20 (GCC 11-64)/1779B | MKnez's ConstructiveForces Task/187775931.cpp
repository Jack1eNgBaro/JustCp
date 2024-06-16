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
 
pii solve(int n){
 pii ans;
 for(int a=-5000;a<=5000;a++){
  if(a == 0) continue;
  
  int b = -(a + 1);
  int s = a + b;
 
  int da = (n + 1) / 2;
  int db = n / 2;
  
  if(da * a + db * b == s){
   return {a, b};
  }  
  
 }
 return {-1, -1};
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  if(n == 1){
   cout << "YES\n" << "1\n";
  }else{
   if(n % 2 == 1){
    pii ans = solve(n);
    if(ans.first == -1 && ans.second == -1){
     cout << "NO\n";
    }else{
     cout << "YES\n";
     for(int i=1;i<=n;i++){
      if(i % 2 == 1) cout << ans.first << " ";
      else cout << ans.second << " ";
     }
     cout << "\n";
    }
   }
   else{
    cout << "YES\n";
    for(int i=1;i<=n;i++){
     if(i % 2 == 1) cout << 1 << " ";
     else cout << "-1 "; 
    }
    cout << "\n";
   }
  }
 }
 return 0;
}