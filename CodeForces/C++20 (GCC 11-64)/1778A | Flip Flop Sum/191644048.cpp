#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int maxn = 1e5;
const int mod = 1e9 + 7;
 
int tc;
 
main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  int a[n + 1];
  
  for(int i=1;i<=n;i++) cin >> a[i];
  
  if(n <= 2){
   cout << (-1 * a[1]) + (-1 * a[2]) << "\n";
   continue;
  }
  
  int ok = 0, x = 0;
  for(int i=1;i<n;i++){
   if(a[i] == -1 && a[i + 1] == -1){
    ok = 1;
    a[i] = a[i + 1] = 1;
    break;
   }else{
    if(a[i] != a[i + 1]) x = 1;
   }
  }
   
  if(ok){
   int s = 0;
   for(int i=1;i<=n;i++) s += a[i]; 
   cout << s << "\n";
  }else{
   if(x){
    int s = 0;
    for(int i=1;i<=n;i++) s += a[i]; 
    cout << s << "\n";
   }else{
    a[1] = -a[1];
    a[2] = -a[2];
    int s = 0;
    for(int i=1;i<=n;i++) s += a[i]; 
    cout << s << "\n";
   }
  }
 }  
   
 return 0;
}