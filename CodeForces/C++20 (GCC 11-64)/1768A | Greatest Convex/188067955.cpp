#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
int nt(int n){
 for(int i=2;i<=sqrt(n);i++){
  if(n % i == 0) return 0;
 }
 return 1;
}
 
main()
{
 file();
 
 int tc; cin >> tc;
 while(tc--)
 {
  int k; cin >> k;
  cout << k-1 <<"\n";
 }
 
 return 0;
}