#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
  
 int n; cin >> n;
 ll f[n + 1]; 
  f[0] = 1; f[1] = 0;
 for(int i=2;i<=n;i++) f[i] = 2*f[i - 2];
 cout << f[n];
 return 0;
}