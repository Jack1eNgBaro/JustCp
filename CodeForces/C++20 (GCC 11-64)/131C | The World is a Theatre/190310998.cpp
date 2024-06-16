#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m, t;
//ans = C(4,n) * C(1,m) * C(t - 5, n + m - 5)
 
int C(int n, int k){
 int ans = 1;
 for(int i=0;i<k;i++){
  ans *= (n - i);
  ans /= (i + 1);
 }
 return ans;
}
 
main(){
 cin >> n >> m >> t;
 int ans = 0;
 for(int i=4;i<t;i++){
  ans += C(n, i) * C(m, t - i);
 }
 cout << ans;
 return 0;
}